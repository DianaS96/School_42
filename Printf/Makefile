NAME = libftprintf.a

SRC = ft_printf.c \
	  my_print_c.c \
	  my_print_id.c \
	  my_print_p.c \
	  my_print_perc.c \
	  my_print_s.c \
	  my_print_s.c \
	  my_print_u.c \
	  my_print_x.c \
	  check_flags.c \
	  ft_itoa.c\
	  ft_itoa_x.c \
	  ft_utoa.c \
	  ft_printf_utils.c

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

#Optimization flag
OPTFLAGS = -O2

# We take SRC files and change .c on .o
OBJ = ${patsubst %.c,%.o,${SRC}}

# We take SRC files and change .c on .d
D_FILES = ${patsubst %.c,%.d,${SRC}}

# all depends from libftprintf.a
all: ${NAME}

# Creating library
# $? - sort of placeholder (Makefile replaces $? with files that were modified after target)
$(NAME): ${OBJ}
	ar rc ${NAME} $?
	ranlib ${NAME}

# Compile ".c" files
# Every file .o depends from relevant .c
# Instead of $< Makefile will put the first dependency of our rule (in our case it will be .c file)
# $@ will be replaced with target (in our case - .o file)
# -MD flag will generate .d file that will contain dependencies from header
%.o : %.c 
	${CC} ${CFLAGS} -c $< -o $@ -MD
#including all header's dependencies 
include $(wildcard $(D_FILES))

# Remove all ".o" and ".d" files
clean:
	@rm -f ${OBJ} ${D_FILES}

# Remove library and call clean
fclean: clean
	@rm -f ${NAME}

re: fclean all

# Telling Makefile that all, clean, fclean and re are not files
.PHONY: all clean fclean re

