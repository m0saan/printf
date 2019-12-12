/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:52:53 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/06 15:02:08 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
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
       printf("166 %06.2d", -128);
       printf("%s", "XX\n");
       printf("167 %06.2d", 128);
       printf("%s", "XX\n\n\n");

       printf("<------------------------------------------------->\n\n");

       printf("166 %06.2d", -128);
       printf("%s", "XX\n");
       printf("167 %06.2d", 128);
       printf("%s", "XX\n");

       int i = printf("Orig : %c === s%chool is %cool\n", 'a', 'c', 'c');
       int j = printf("Mine : %c === s%chool is %cool\n", 'a', 'c', 'c');
       printf("i = %d\nj = %d\n", i, j);


       printf("-----------------------------------------------\n\n");

       printf("%d\n",0);
       printf("%d\n",-7);
       printf("%d\n",1560133635);
       printf("%d\n",-2035065302);
       printf("%5d\n",0);
       printf("%5d\n",-7);
       printf("%5d\n",1560133635);
       printf("%5d\n",-2035065302);
       printf("%-5d\n",0);
       printf("%-5d\n",-7);
       printf("%-5d\n",1560133635);
       printf("%-5d\n",-2035065302);
       printf("%05d\n",0);
       printf("%05d\n",-7);
       printf("%05d\n",1560133635);
       printf("%05d\n",-2035065302);
       printf("%-5d\n",0);
       printf("%-5d\n",-7);
       printf("%-5d\n",1560133635);
       printf("%-5d\n",-2035065302);

       int i = printf("$%5.10s$\n","Hello 1337!");
       int y = printf("$%5.10s$\n", "Hello 1337!");
       printf("'%5s'\n","abcdefg");
       printf("'%5s'\n","");
       printf("'%5s'\n","a");
       printf("'%5s'\n","ab");
       printf("'%5s'\n","abcdefg");
       printf("'%-5s'\n","");
       printf("'%-5s'\n","a");
       printf("'%-5s'\n","ab");
       printf("'%-5s'\n","abcdefg");
    printf("1 %02d\n", 100);
    printf("2 %03d\n", 100);
    printf("3 a%03d\na", 100);
    printf("4 %04d\n", 100);
    printf("5 %02d\n", -100);
    printf("6 %03d\n", -100);
    printf("7 %05d\n", -100);
    printf("8 %04d\n", 0);
    printf("9 %01d\n", 0);
    printf("10 a%01da\n", 0);
    printf("11 %2.3d\n", 100);
    printf("12 %3.3d\n", 100);
    printf("13 a%3.3da\n", 100);
    printf("14 %4.3d\n", 100);
    printf("15 %2.3d\n", -100);
    printf("16 %3.3d\n", -100);
    printf("17 %4.3d\n", -100);
    printf("18 %4.3d\n", 0);
    printf("19.1 %1.3d\n", 0);
    printf("19 a%1.3da\n", 0);
    printf("20 %2.0d\n", 100);
    printf("21 %3.0d\n", 100);
    printf("22 a%3.0da\n", 100);
    printf("23 %4.0d\n", 100);
    printf("24 %2.0d\n", -100);
    printf("25 %3.0d\n", -100);
    printf("26 %4.0d\n", -100);
    printf("27 %4.0d\n", 0);
    printf("28 %1.0d\n", 0);
    printf("29 %4.d\n", 100);
    printf("30 %2.d\n", -100);
    printf("31 %3.d\n", -100);
    printf("32 %4.d\n", -100);
    printf("33 %4.d\n", 0);
    printf("34 %1.d\n", 0);
    printf("35 a%1.0da\n", 0);
    printf("36 %2.7d\n", 100);
    printf("37 %15.7d\n", 100);
    printf("38 a%3.7da\n", 100);
    printf("39 %4.7d\n", 100);
    printf("40 %2.7d\n", -100);
    printf("41 %3.7d\n", -100);
    printf("42 %15.7d\n", -100);
    printf("43 %4.7d\n", 0);
    printf("44 %1.7d\n", 0);
    printf("45 a%1.7da\n", 0);
    printf("46 %3d\n", 100);
    printf("47 a%3da\n", 100);
    printf("48 %4d\n", 100);
    printf("49 %2d\n", -100);
    printf("50 %3d\n", -100);
    printf("51 %4d\n", -100);
    printf("52 %4d\n", 0);
    printf("53 %1d\n", 0);
    printf("54 a%1da\n", 0);
    printf("55 %-2d\n", 100);
    printf("56 %-3d\n", 100);
    printf("57 a%-3da\n", 100);
    printf("58%-4d\n", 100);
    printf("59 %-2d\n", -100);
    printf("60 %-3d\n", -100);
    printf("61 %-4d\n", -100);
    printf("62 %-4d\n", 0);
    printf("63 %-1d\n", 0);
    printf("64 a%-1da\n", 0);
    printf("65 %.3d\n", 100);
    printf("66 %.3d\n", 100);
    printf("67 a%.3da\n", 100);
    printf("68 %.3d\n", 100);
    printf("69 %.3d\n", -100);
    printf("70 %.3d\n", -100);
    printf("71 %.3d\n", -100);
    printf("72 %.3d\n", 0);
    printf("73 %.3d\n", 0);
    printf("74 a%.3da\n", 0);
    printf("75 %.0d\n", 100);
    printf("75 %.0d\n", 100);
    printf("76 a%.0da\n", 100);
    printf("77 %.0d\n", 100);
    printf("78 %.0d\n", -100);
    printf("79 %.0d\n", -100);
    printf("80%.0d\n", -100);
    printf("81 %.0d\n", 0);
    printf("82 %.0d\n", 0);
    printf("83 %.d\n", 100);
    printf("84 %.d\n", -100);
    printf("85 %.d\n", -100);
    printf("86 %.d\n", -100);
    printf("87 %.d\n", 0);
    printf("88 %.d\n", 0);
    printf("89 a%.0da\n", 0);
    printf("90 %.7d\n", 100);
    printf("91 %5.7d\n", 100);
    printf("92 a%.7da\n", 100);
    printf("93 %.7d\n", 100);
    printf("94 %.7d\n", -100);
    printf("95 %.7d\n", -100);
    printf("96 %5.7d\n", -100);
    printf("97 %.7d\n", 0);
    printf("98 %.7d\n", 0);
    printf("99a%.7da\n\n", 0);
    printf("%d\n", 100);
    printf("%d\n", 0);
    printf("a%da\n", 100);
    printf("a%da\n", 0);
    printf("%2d\n", 100);
    printf("%3d\n", 100);
    printf("a%3da\n", 100);
    printf("%4d\n", 100);
    printf("%2d\n", -100);
    printf("%3d\n", -100);
    printf("%4d\n", -100);
    printf("%4d\n", 0);
    printf("%1d\n", 0);
    printf("a%1da\n", 0);
    printf("%-3d\n", 100);
    printf("a%-3da\n", 100);
    printf("%-4d\n", 100);
    printf("%-2d\n", -100);
    printf("%-3d\n", -100);
    printf("%-4d\n", -100);
    printf("%-4d\n", 0);
    printf("%-1d\n", 0);
    printf("a%-1da\n", 0);

    printf("----------------------------------------------\n\n");
    ft_printf("1 %02d\n", 100);
    ft_printf("2 %03d\n", 100);
    ft_printf("3 a%03d\na", 100);
    ft_printf("4 %04d\n", 100);
    ft_printf("5 %02d\n", -100);
    ft_printf("6 %03d\n", -100);
    ft_printf("7 %05d\n", -100);
    ft_printf("8 %04d\n", 0);
    ft_printf("9 %01d\n", 0);
    ft_printf("10 a%01da\n", 0);
    ft_printf("11 %2.3d\n", 100);
    ft_printf("12 %3.3d\n", 100);
    ft_printf("13 a%3.3da\n", 100);
    ft_printf("14 %4.3d\n", 100);
    ft_printf("15 %2.3d\n", -100);
    ft_printf("16 %3.3d\n", -100);
    ft_printf("17 %4.3d\n", -100);
    ft_printf("18 %4.3d\n", 0);
    ft_printf("19.1 %1.3d\n", 0);
    ft_printf("19 a%1.3da\n", 0);
    ft_printf("20 %2.0d\n", 100);
    ft_printf("21 %3.0d\n", 100);
    ft_printf("22 a%3.0da\n", 100);
    ft_printf("23 %4.0d\n", 100);
    ft_printf("24 %2.0d\n", -100);
    ft_printf("25 %3.0d\n", -100);
    ft_printf("26 %4.0d\n", -100);
    ft_printf("27 %4.0d\n", 0);
    ft_printf("28 %1.0d\n", 0);
    ft_printf("29 %4.d\n", 100);
    ft_printf("30 %2.d\n", -100);
    ft_printf("31 %3.d\n", -100);
    ft_printf("32 %4.d\n", -100);
    ft_printf("33 %4.d\n", 0);
    ft_printf("34 %1.d\n", 0);
    ft_printf("35 a%1.0da\n", 0);
    ft_printf("36 %2.7d\n", 100);
    ft_printf("37 %15.7d\n", 100);
    ft_printf("38 a%3.7da\n", 100);
    ft_printf("39 %4.7d\n", 100);
    ft_printf("40 %2.7d\n", -100);
    ft_printf("41 %3.7d\n", -100);
    ft_printf("42 %15.7d\n", -100);
    ft_printf("43 %4.7d\n", 0);
    ft_printf("44 %1.7d\n", 0);
    ft_printf("45 a%1.7da\n", 0);
    ft_printf("46 %3d\n", 100);
    ft_printf("47 a%3da\n", 100);
    ft_printf("48 %4d\n", 100);
    ft_printf("49 %2d\n", -100);
    ft_printf("50 %3d\n", -100);
    ft_printf("51 %4d\n", -100);
    ft_printf("52 %4d\n", 0);
    ft_printf("53 %1d\n", 0);
    ft_printf("54 a%1da\n", 0);
    ft_printf("55 %-2d\n", 100);
    ft_printf("56 %-3d\n", 100);
    ft_printf("57 a%-3da\n", 100);
    ft_printf("58%-4d\n", 100);
    ft_printf("59 %-2d\n", -100);
    ft_printf("60 %-3d\n", -100);
    ft_printf("61 %-4d\n", -100);
    ft_printf("62 %-4d\n", 0);
    ft_printf("63 %-1d\n", 0);
    ft_printf("64 a%-1da\n", 0);
    ft_printf("65 %.3d\n", 100);
    ft_printf("66 %.3d\n", 100);
    ft_printf("67 a%.3da\n", 100);
    ft_printf("68 %.3d\n", 100);
    ft_printf("69 %.3d\n", -100);
    ft_printf("70 %.3d\n", -100);
    ft_printf("71 %.3d\n", -100);
    ft_printf("72 %.3d\n", 0);
    ft_printf("73 %.3d\n", 0);
    ft_printf("74 a%.3da\n", 0);
    ft_printf("75 %.0d\n", 100);
    ft_printf("75 %.0d\n", 100);
    ft_printf("76 a%.0da\n", 100);
    ft_printf("77 %.0d\n", 100);
    ft_printf("78 %.0d\n", -100);
    ft_printf("79 %.0d\n", -100);
    ft_printf("80%.0d\n", -100);
    ft_printf("81 %.0d\n", 0);
    ft_printf("82 %.0d\n", 0);
    ft_printf("83 %.d\n", 100);
    ft_printf("84 %.d\n", -100);
    ft_printf("85 %.d\n", -100);
    ft_printf("86 %.d\n", -100);
    ft_printf("87 %.d\n", 0);
    ft_printf("88 %.d\n", 0);
    ft_printf("89 a%.0da\n", 0);
    ft_printf("90 %.7d\n", 100);
    ft_printf("91 %5.7d\n", 100);
    ft_printf("92 a%.7da\n", 100);
    ft_printf("93 %.7d\n", 100);
    ft_printf("94 %.7d\n", -100);
    ft_printf("95 %.7d\n", -100);
    ft_printf("96 %5.7d\n", -100);
    ft_printf("97 %.7d\n", 0);
    ft_printf("98 %.7d\n", 0);
    ft_printf("99a%.7da\n", 0);
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
    */
        int i = printf("%10d\n",100);
        int j = ft_printf("%10d\n",100);
        printf("i : %d\nj : %d\n", i,j);
    return (0);
}
