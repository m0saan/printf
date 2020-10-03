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

## Examples

- `ft_printf("Hello, 1337FIL\n")` _prints "Hello, 1337FIL", followed by a new line_
- `ft_printf("%s", "Hello")` _prints "Hello"_
- `ft_printf("This is a number: %d", 1337)` _prints "This is a number: 1337"_

---

# How To Install

- `git clone https://github.com/MoBoustta/printf.git`
- `cd printf`
- `make`
- `make clean`
- `create a .c file and call include ft_printf header`
- `call ft_printf()`
- `gcc libftprintf.a file.c; ./aout`

## Format Specifiers

A format specifier follows this prototype: `%[flags][width][.precision][length]type`
The following format specifiers are supported:

### Supported Types

| Type   | Output                                                    |
| ------ | --------------------------------------------------------- |
| d or i | Signed decimal integer                                    |
| u      | Unsigned decimal integer                                  |
| x      | Unsigned hexadecimal integer (lowercase)                  |
| X      | Unsigned hexadecimal integer (uppercase)                  |
| c      | Single character                                          |
| s      | String of characters                                      |
| p      | Pointer address                                           |
| %      | A % followed by another % character will write a single % |

### Supported Flags

| Flags | Description                                                                                                |
| ----- | ---------------------------------------------------------------------------------------------------------- |
| -     | Left-justify within the given field width; Right justification is the default.                             |
| 0     | Left-pads the number with zeros (0) instead of spaces when padding is specified (see width sub-specifier). |

### Supported Width

| Width    | Description                                                                                                                                                                                          |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| \*       | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                        |

### Supported Precision

| Precision | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| .number   | For integer specifiers (d, i, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.<br>For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.<br>If the period is specified without an explicit value for precision, 0 is assumed. |
| .\*       | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |

## Author

- **moboustt** - [moboustta6@gmail.com](https://github.com/MoBoustta)
