/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:19:05 by yfarini           #+#    #+#             */
/*   Updated: 2019/12/26 17:32:52 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "../ft_printf.h"
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
pid_t   pid;
int    	sign;
int		status;
FILE	*fp;
#define RED 	"\033[0;31m"
#define GREEN 	"\033[0;32m"
#define YELLOW 	"\033[0;33m"
#define RST	"\033[0m"

void	delay(unsigned int msec)
{
    clock_t s = clock();
    while(((clock() - s) brew install bash-completion/ CLOCKS_PER_SEC )* 1000 < msec)
    {
        status = -100;
        waitpid(pid, &status, WNOHANG);
        if (status != -100)
            break;
    }
}

#define SEGF(f)	do{\
    if((pid = fork()) == -1)\
    exit (EXIT_FAILURE);\
    if (pid == 0)\
    {\
        do{ f; }while(0);\
        exit (EXIT_SUCCESS);\
    }\
    else\
    {\
        delay(50);\
        status = -100;\
        waitpid(pid, &status, WNOHANG);\
        kill(pid, SIGKILL);\
        waitpid(pid, &status, 0);\
        sign = status == -100 ? 0 : status == 9 ? 2 : 1;\
    }\
}while(0)


#define	SP(file,...)	do{\
    fp = fopen(file, "a+");\
    fprintf(fp,__VA_ARGS__);\
    fclose(fp);\
}while(0)

#define T(...)	do{\
    SEGF(printf("\tReturn: %d\n", ft_printf(__VA_ARGS__)));\
    if(sign == 1)\
    printf("SEGV\n");\
    if(sign == 2)\
    printf("TIMEOUT\n");\
    SP("EXPECTED","\tReturn: %d\n", fprintf(fp, __VA_ARGS__));\
    SP("TESTS","%s\n", #__VA_ARGS__);\
}while(0)
int main()
{
    setbuf(stdout,NULL);
    printf("--> \"%%That\" EASY\n");
    SP("EXPECTED","--> \"%%That\" EASY\n");
    SP("TESTS","--> \"%%That\" EASY\n");
    char *s = "My ft_printf";
	char c, x;
	int number = -2147483648;
	int hexa = 35698;
	int hexa1 = -35698;
	unsigned int num = 4294967295;
	int nam = 2147483647; 

	c = 'M';
	x = 'L';
    int len2 = 66697+97+9;
    unsigned int ui;
    void *addr;
    char    *str = "astek";
    char    stre[] = {'a', 's', 10, 'e', 'k', 0};
    char q = 'H';
    char *p = "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\n\n\n\n\n\n\n\n\n\n\\t\t\t\t\t\t\t\t\t\t\t\t\\v\v\v\v\v\v\v\v\v\v\v\v\e\e\e\e\e\e\e\e\e\e\e\e\e\e\e\e\e\e\\v\v\v\v\vv\\r\r\r\r\r\r\r\r\r\r\r\r\r\r\\r\r\\r\r\r\r\r\r\r\r\r\r\f\f\f\f\f\\f\f\\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\\f\f\f\f\\f\f\\f\\f\\f\\f\f\\f\\t\t\t\\t\t\\t\\t\tHere are two poems from a reddit user /u/poem_f_your_sprog.They describe the lif\e of a little boy named Timmy.=========== Poem A ====================== Poem B ======================= DONE ============What an asshole";

    T("Let's try to T a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    T("Length:[%d, %i]\n", len2, len2);
    T("Negative:[%d]\n", -762534);
    T("Unsigned:[%u]\n", ui);
    T("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    T("Character:[%c]\n", 'H');
    T("String:[%s]\n", "I am a string !");
    T("Address:[%p]\n", addr);
    T("Percent:[%%]\n");
    T("Len:[%d]\n", len2);
    T("%c%c   hi  %s    - - ***\n", q, q, p);
    T("Let's try to T: a [[%s]x] woof\n more [%c]sentence.\n", p, q);
    T("%%%s%d%%-%c %%%%\n", p, 10, q);
    T("%d%c%d%%d\n", 130, 130, 50);
    T("___________________________________________________________________\n\n");
    T("\t@%%%-12d, %.s%000004.i %% %10.*u    %-1X, %10p %%%%%000--0-0----0-0-0-0-0-5.*%%.p\n", -1996, "-99 fuck the world\n", 1, 6, -22, 35764523, (void *)328947, -4, (void *)0);
    T("%s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek\n", str, str, str, str, str, str);
    T("=> [s S s ...] : %s %s %s %s %s %s %s %s %s %s %s %s\n", str, stre, str, stre, str, stre, str, stre, str, stre, str, stre);
    printf("--> \"%%cspdiuxX\" GET CRAZY AS FARK ;)\n");
    SP("EXPECTED","--> \"%%cspdiuxX\" GET CRAZY AS FARK ;)\n");
    SP("TESTS","--> \"%%cspdiuxX\" GET CRAZY AS FARK ;)\n");
    T("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
    T("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x", 7,5, "ABC",15,0,20,0x99);
    T("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20);
    T("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
    T("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
    T("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
    /*
    T("{%d}\n", printf("\033[1;32mTest 15 => \033[0m|%C|", L'🧀'));
    T("{%d}\n", printf("\033[1;32mTest 16 => \033[0m|%22C|", L'🧀'));
    T("{%d}\n", printf("\033[1;32mTest 16b => \033[0m|%-22C|", L'🧀'));
    T("{%d}\n", printf("\033[1;32mTest 17 => \033[0m|%4C|", L'😐'));
    T("{%d}\n", printf("\033[1;32mTest 18 => \033[0m|%4C|", L'😐'));
    T("{%d}\n", printf("\033[1;32mTest 19 => \033[0m|%22C|", L'😐'));
    T("{%d}\n", printf("\033[1;32mTest 20 => \033[0m|%s|", NULL));
    */
    T("{%d}\n", printf("\033[1;32mTest 21 => \033[0m|%C|", L'᳄'));
    T("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%2C|", L'🧀'));
    T("%s can write a simple text with string\n", s);
	T("%s can write a simple text with string and char %c\n", s, x);
	T("%d can print a simple number\n", number);
	T("%s can write a simple text with string and %c and %d\n", s, c, number);
	T("%s can write a simple text with string and %c and %d and [%p]\n", s, c, number, s);
	T("%s can write a simple text with string and %c and %d and [%p] also %x\n", s, c, number, s, hexa);
	T("%s can write a simple text with string and %c and %d and [%p] also %x can he make %x\n", s, c, number, s, hexa, hexa1);
	T("%s can write a simple text with string and %c and %d and [%p] also %x can he make %x %X %X unsigned %u signed %i\n", s, c, number, s, hexa, hexa1, hexa, hexa1, num, nam);
	T("test with flags [-] signed int %-d signed int2 %-d unsigned int %-u string %-s\n", hexa, hexa1, nam, s);
	T("test with flags [-] signed int %-dd signed int2 %-dd unsigned int %-uu string %-ss\n", hexa, hexa1, nam, s);
	T("test with flags [-] signed int %-5dd signed int2 %-5dd unsigned int %-5uu string %-5ss\n", hexa, hexa1, nam, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss\n", hexa, hexa1, nam, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-c%-10c\n", hexa, hexa1, nam, s, c, c);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc\n", hexa, hexa1, nam, s, c, c, c);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc %-p\n", hexa, hexa1, nam, s, c, c, c, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc %-pp\n", hexa, hexa1, nam, s, c, c, c, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc%-1pp\n", hexa, hexa1, nam, s, c, c, c, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc%-10pp\n", hexa, hexa1, nam, s, c, c, c, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uu string %-20ss%-10c%cc%-10cc%-20pp\n", hexa, hexa1, nam, s, c, c, c, s);
	T("test with flags [-] signed int %-10dd signed int2 %-8dd unsigned int %-uuu string %-20ss%-10c%cc%-10ccc%-100pp%p\n", hexa, hexa1, nam, s, c, c, c, s, s);
	T("test with flags [*] and [-] %0*X%010XX %-10x hexadecimal int %-*Xxd%-10xX  signed int %-*dd char %-*c c %-*c string %-*s%-*s unsigned int %-*ud%ud\n", 10, num, hexa1, hexa, 10, hexa1, hexa, 10, hexa1, 10, x, 1, c, 12, s, 13, s, 10, num, num);
	T("test with [width_field] s%100s%1sp%100p%1pX%10xx%1Xxnd%10d%0d\n", s, s, s, s, hexa, hexa1, hexa, hexa1);
	T("test with [width_field] s%*s%*sp%*p%*pX%*xx%*Xxnd%*d%*d\n", 100 , s, 1, s, 100, s,1, s, 10, hexa, 1,  hexa1, 10, hexa, 0 ,hexa1);
	T("%1.d\n", hexa);
	T("%5.d\n", hexa);
	T("%10.d\n", hexa);
	T("%1.x\n", hexa);
	T("%5.x\n", hexa);
	T("%10.x\n", hexa);
	T("%1.X\n", hexa);
	T("%5.X\n", hexa);
	T("%10.X\n", hexa);
	T("%1.u\n", hexa);
	T("%5.u\n", hexa);
	T("%10.u\n", hexa);
	T("%1.s\n", s);
	T("%5.s\n", s);
	T("%10.s\n", s);
}
