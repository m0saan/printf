#include "../libft.h"
#include "../ft_printf.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
    /*
       ft_printf("%d\n", 100);
       ft_printf("%d\n", 0);
       ft_printf("a%da\n", 100);
       ft_printf("a%da\n", 0);
       ft_printf("%2d\n", 100);
       ft_printf("%3d\n", 100);
       ft_printf("a%3da\n", 100);
       ft_printf("%4d\n", 100);
       ft_printf("%2d\n", -100);
       ft_printf("%3d\n", -100);
       ft_printf("%4d\n", -100);
       ft_printf("%4d\n", 0);
       ft_printf("%1d\n", 0);
       ft_printf("a%1da\n", 0);
       ft_printf("%-3d\n", 100);
       ft_printf("a%-3da\n", 100);
       ft_printf("%-4d\n", 100);
       ft_printf("%-2d\n", -100);
       ft_printf("%-3d\n", -100);
       ft_printf("%-4d\n", -100);
       ft_printf("%-4d\n", 0);
       ft_printf("%-1d\n", 0);
       ft_printf("a%-1da\n", 0);
       ft_printf("----------------------------------------------\n\n");
       ft_ft_printf("%d\n", 100);
       ft_ft_printf("%d\n", 0);
       ft_ft_printf("a%da\n", 100);
       ft_ft_printf("a%da\n", 0);
       ft_ft_printf("%2d\n", 100);
       ft_ft_printf("%3d\n", 100);
       ft_ft_printf("a%3da\n", 100);
       ft_ft_printf("%4d\n", 100);
       ft_ft_printf("%2d\n", -100);
       ft_ft_printf("%3d\n", -100);
       ft_ft_printf("%4d\n", -100);
       ft_ft_printf("%4d\n", 0);
       ft_ft_printf("%1d\n", 0);
       ft_ft_printf("a%1da\n", 0);
       ft_ft_printf("%-3d\n", 100);
       ft_ft_printf("a%-3da\n", 100);
       ft_ft_printf("%-4d\n", 100);
       ft_ft_printf("%-2d\n", -100);
       ft_ft_printf("%-3d\n", -100);
       ft_ft_printf("%-4d\n", -100);
       ft_ft_printf("%-4d\n", 0);
       ft_ft_printf("%-1d\n", 0);
       ft_ft_printf("a%-1da\n", 0);
       */
    int i = printf("%02d\n", 100);
    int j = ft_printf("%02d\n", 100);
    printf("i : %d\nj : %d\n", i,j);
}
