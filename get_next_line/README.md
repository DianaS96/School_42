# get_next_line :outbox_tray:

The aim of this project is to write a function that returns a line from fd.

You can find subject <a href="https://github.com/DianaS96/get_next_line/blob/3e7315542405c7499e68ea7a85454c0e662c8945/en.subject.pdf">HERE</a>.

# Usage

The full programm should be compiled in this way (please, pay attention, that in this repo you can find the function, not the program - there is no main function in .c files):

`cc -Wall -Wextra -Werror -D BUFFER_SIZE=xx <files.c> <file<.h>,`

where `BUFFER_SIZE` is number of characters to read in buffer per 1 read call.

## Example of main function for calling get_next_line
You can use the main function below to call get_next_line function. As a result you will see all lines from file "XXX" printed in your terminal. 
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char    *line;
    int     i;
    int     fd;

    i = 0;
    fd = open("XXX", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%i) %s", i, line);
        free(line);
        i++;
    }
    return (0);
}
```
