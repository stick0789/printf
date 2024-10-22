#include "ft_printf.h"

int main(void)
{
	char *str = "hola";
	char c = 'c';
	int nb = -2147483648;
	unsigned int uint = -123;
	unsigned int hexa = 4294967295;//1E240
	int *null_ptr = NULL;
	int variable = 42;
	void *void_ptr = &variable;
	//int hexa = 123456;//1E240

	printf("\nPrintf Result:  %i\n", printf("el char es; %c\nla str es: %s\nel numero es: %i\nel u int es: %u\ny el pct es %%", c, str, nb, uint));
	ft_printf("\nFt_printf Result: %i\n", ft_printf("el char es; %c\nla str es: %s\nel numero es: %i\nel u int es: %u\ny el pct es %%", c, str, nb, uint));
	printf("\nPrintf Result:  %i\n", printf("el numero es: %i\nel u int es: %u\nel hexa es: %x",nb, uint, hexa));
	ft_printf("\nFt_printf Result: %i\n", ft_printf("el numero es: %i\nel u int es: %u\nel hexa es: %x",nb, uint, hexa));
	printf("\nPrintf Result:  %i\n", printf("el hexa es: %X", hexa));
	ft_printf("\nFt_printf Result: %i\n", ft_printf("el hexa es: %X", hexa));
	printf("\nPrintf Result:  %i\n", printf("el numero es: %i\n",nb));
	ft_printf("\nFt_printf Result: %i\n", ft_printf("el numero es: %i\n",nb));
	printf("\nPrintf Result:  %i\n", printf("el puntero vacio es: %p\ny el de direccion es: %p\n",null_ptr, void_ptr));
	ft_printf("\nFt_printf Result: %i\n", ft_printf("el puntero vacio es: %p\ny el de direccion es: %p\n",null_ptr, void_ptr));

	return 0;
}
