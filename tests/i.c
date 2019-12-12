#include "ft_printf.h"
#include "libft.h"
int main()
{
    printf("%.*s\n", -5, "ABC");
    printf("%.*s\n", -5, "ABC");
    ft_printf("%.*s\n", -5, "ABC");
    /*
    ft_printf("%.*s\n", -5, "ABC");
    ft_printf("%.*s\n", -5, "ABC");
    ft_printf("a%.*sa\n", -5, "ABC");
    ft_printf("%.*s\n", -5, NULL);
    ft_printf("a%.*sa\n", -5, NULL);
    ft_printf("%.*s\n", -5, NULL);
    ft_printf("%.*s\n", -5, NULL);
    ft_printf("%.*s\n", -5, "");
    ft_printf("%.*s\n", -5, "");
    ft_printf("a%.*sa\n", -5, "");
    ft_printf("%.*s\n", -5, "ABC");
    ft_printf("%.*s\n", -5, "ABC");
    ft_printf("%.*s\n", -5, "ABC");
    ft_printf("a%.*sa\n", -5, "ABC");
    */
    return (0);
}
