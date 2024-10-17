#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>  // Para write
#include <stdlib.h>

static int      ft_len(long int n)
{
        int     len;

        len = 1;
        if (n < 0)
        {
                n *= -1;
                len++;
        }
        while (n > 9)
        {
                n /= 10;
                len++;
        }
        return (len);
}

static void     ft_putn_save(long int n, char *s, int *i)
{
        if (n > 9)
        {
                ft_putn_save(n / 10, s, i);
                ft_putn_save(n % 10, s, i);
        }
        else
                s[(*i)++] = n + '0';
}

char    *ft_itoa(int n)
{
        char            *s;
        int                     i;
        int                     len;
        long int        nbr;

        nbr = (long int)n;
        len = ft_len(nbr);
        s = (char *)malloc(sizeof(char) * (len + 1));
        if (!s)
                return (NULL);
        i = 0;
        if (nbr < 0)
        {
                s[i++] = '-';
                nbr *= -1;
        }
        ft_putn_save(nbr, s, &i);
        s[i] = '\0';
        return (s);
}

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

int ctrl_putchar(char c)
{
    write(1, &c, 1);  // Reemplaza ft_putchar_fd
    return 1;
}

int     ctrl_putstr(char *s)
{
        if (!s)
                return (ctrl_putstr("(null)"));
        write(1, s, ft_strlen(s));
        return (ft_strlen(s));
}

int     ctrl_putnbr(int n)
{
        long nb;
        
        nb = n;
        if (nb < 0)
        {
                ctrl_putchar('-');
                nb *= -1;
        }
        if (nb <= 9)
                ctrl_putchar(nb + '0');
        else
        {
                ctrl_putnbr(nb / 10);
                ctrl_putnbr(nb % 10);
        }
        return (ft_strlen(ft_itoa(nb)));
}

unsigned int	ctrl_uint(unsigned int n)
{
	int	size; // Variable que cuenta el número de caracteres impresos

	size = 0;
	if (n > 9)
	{
		size = ctrl_uint(n / 10);  // Llamada recursiva
		if (n == -1)                 // Si hubo error en la recursión
			return (-1);               // Retorna -1 si hubo error
		n = n % 10;                    // Obtener el último dígito de 'n'
	}
	if (n <= 9)
	{
		if (ctrl_putchar((n + '0')) == -1)  // Imprimir el dígito convertido en carácter
			return (-1);                 // Retorna -1 si hubo error al imprimir
		size++;  // Incrementa el contador de caracteres impresos
	}
	return (size);  // Retorna el número total de caracteres impresos
}

static int ft_printf_process(va_list args, char fs)
{
    int size = 0;

    if (fs == 'c')
        size += ctrl_putchar(va_arg(args, int));
    else if (fs == 's')
        size += ctrl_putstr(va_arg(args, char *));
    else if (fs == 'd' || fs == 'i')
        size += ctrl_putnbr(va_arg(args, long));
    return size;
}

int ft_printf(char const *format, ...)
{
    va_list args;
    int size = 0;
    int i = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            size += ft_printf_process(args, format[i + 1]);
            i++; 
        }
        else
        {
            size += ctrl_putchar(format[i]); 
        }
        i++;
    }
    va_end(args);  
    return size;
}

int main(void)
{
    char *str = "hola";
    char c = 'c';
    int nb = 2147483648;

    printf("\nPrintf Result:  %i\n", printf("el char es; %c\nla str es: %s\nel numero es: %i", c, str, nb));
    ft_printf("\nFt_printf Result: %i\n", ft_printf("el char es; %c\nla str es: %s\nel numero es: %i", c, str, nb));
    return 0;
}
