# Ft_printf :printer:

This repo contains function **`ft_printf`** that copies work of the following libc’s printf function features:
* %c print a single character.
* %s print a string of characters.
* %p The void * pointer argument is printed in hexadecimal.
* %d print a decimal (base 10) number.
* %i print an integer in base 10.
* %u print an unsigned decimal (base 10) number.
* %x print a number in hexadecimal (base 16), with lowercase.
* %X print a number in hexadecimal (base 16), with uppercase.
* %% print a percent sign.

# Usage
To use ft_printf function follow the following instructions:
* create libftprintf.a running **`make`** in terminal;
* include 'ft_prinf.h" header in all your files where ft_printf function will be used;
* compile files via:
`gcc -Wall -Wextra -Werror {file.c} -L. -lftprintf`
