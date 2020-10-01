# ft_printf

## Description

This project is part of the curriculum provided by 42born2code School. The project is pretty straight forward. ft_printf replicates the C standard library printf() function.

What you should learn from this project:

- Write well-structured and good extensible code.
- You will mainly learn how to use variadic arguments.
- Unix logic
- Rigor

---

## Prototype

`int ft_printf(const char *fmt, ...);`

## Usage

- Prints a string to the standard output, according to a given format.
- Basically it manage the following conversions: cspdiuxX%.
- It manage any combination of the following flags: ’-0.\*’ and minimum field width with all conversions.
- It will be compared with the real printf
- All files were created and compiled on MacOs Sierra 10.12 using GCC 4.8.4 with the command `gcc -Wall -Werror -Wextra -pedantic *.c`
- Returns the number of characters in the output string on success, -1 otherwise
- Call it this way: `ft_printf("format string", arguments...)` where `format string` can contain conversion specifiers and flags, along with regular characters
