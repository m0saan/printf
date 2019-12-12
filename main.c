#include "ft_printf.h"
#include "libft.h"
int main()
{
    /*
       printf("'%2.s'\n", "ABC");
       printf("'%3.s'\n", "ABC");
       printf("'%4.s'\n", "ABC");
       printf("'a%4.sa\n'", "ABC");
       printf("'%1.s'\n", NULL);
       printf("'a%1.sa'\n", NULL);
       printf("'%6.s'\n", NULL);
       printf("'%7.s'\n", NULL);
       printf("'%4.s'\n", "");
       printf("'%1.s'\n", "");
       printf("'a%1.sa'\n", "");
       printf("____________________________\n");
       ft_printf("'%2.s'\n", "ABC");
       ft_printf("'%3.s'\n", "ABC");
       ft_printf("'%4.s'\n", "ABC");
       ft_printf("'a%4.sa\n'", "ABC");
       ft_printf("'%1.s'\n", NULL);
       ft_printf("'a%1.sa'\n", NULL);
       ft_printf("'%6.s'\n", NULL);
       ft_printf("'%7.s'\n", NULL);
       ft_printf("'%4.s'\n", "");
       ft_printf("'%1.s'\n", "");
       ft_printf("'a%1.sa'\n", "");
       printf("'%4.d'\n", 0);
       printf("'%1.d'\n", 0);
       printf("'a%1.0da'\n", 0);
       ft_printf("'%4.d'\n", 0);
       ft_printf("'%1.d'\n", 0);
       ft_printf("'a%1.0da'\n", 0);
       */
    int i = printf("%p\n", (void *)0x0);
    int j = ft_printf("%p\n", (void *)0x0);
    printf("i : %d\nj : %d\n", i, j);

}
