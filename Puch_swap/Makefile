NAME = push_swap

SRC = src/check_arg.c \
		src/ft_atoi.c \
		src/ft_isdigit.c \
		src/ft_strlen.c \
		src/list.c \
		src/main.c \
		src/min_max_mid_find.c \
		src/mini_sort.c \
		src/push_operations.c \
		src/radix_sort.c \
		src/rev_rotate_operations.c \
		src/rotate_operations.c \
		src/simplify_nums.c \
		src/swap_operations.c

INCL = includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

#Optimization flag
OPTFLAGS = -O2

# We take SRC files and change .c on .o
OBJ = ${patsubst %.c,%.o,${SRC}}

D_FILES = ${patsubst %.c,%.d,${SRC}}

# all depends from libftprintf.a
all: ${NAME} 

# $@ will be replaced by  target
${NAME}: ${OBJ} ${SRC}
	${CC} ${CFLAGS} ${OBJ} -o $@
	@echo "\033[0;32m""Executable file push_swap is ready to use""\033[0m"

# $< will be replaced by first dependancy (in our case - .c files)
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}


# Remove all ".o" and ".d" files
clean:
	@rm -f ${OBJ} ${D_FILES}
	@echo "\033[0;33m""All .o and .d files deleted""\033[0m"
# Remove library and call clean
fclean: clean
	@rm -f ${NAME}
	@echo "\033[0;33m""Executable file deleted""\033[0m"

re: fclean all

# Telling Makefile that all, clean, fclean and re are not files
.PHONY: all clean fclean re
