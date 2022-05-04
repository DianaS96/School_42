NAME	= philo

SRC		=	main.c \
			ft_error.c \
			check_args.c \
			ft_init.c \
			time.c \
			utils.c \
			philo_eat.c \
			ft_is_dead.c
			
OBJ		= ${SRC:.c=.o}

D_FILES	= ${SRC:.c=.d}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=thread
#-fsanitize=address
#-fsanitize=thread
#-fsanitize=address

# Telling that "fclean, clean, re and all" are names of rules (not names of files)
.PHONY: fclean clean all re

all: ${NAME}

# $@ will be replaced by target (NAME of program)
${NAME}: ${OBJ} ${SRC}
	${CC} ${CFLAGS} ${OBJ} -o $@
	@echo "\033[0;35m""Executable file created""\033[0m"

# $< will be replaced by first dependency (.c files)
%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@ -MD
include ${wildcard *.d}

# Remove all ".o" and ".d" files
clean: 
	@rm -f ${OBJ} ${D_FILES} 
	@echo "\033[0;33m""All .o and .d files deleted""\033[0m"

# Remove executable file and call clean cmd
fclean: clean
	@rm -f ${NAME}
	@echo "\033[0;33m""Executable file deleted""\033[0m"

re: fclean all

