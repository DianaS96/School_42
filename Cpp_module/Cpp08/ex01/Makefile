NAME =	span

SRC	=	main.cpp \
		Span.cpp

OBJ =	${patsubst %.cpp, %.o, ${SRC}}

D_FILES = ${patsubst %.cpp, %.d, ${SRC}}

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJ} ${SRC} Makefile
	${CC} ${CFLAGS} ${OBJ} -o $@
	@echo "\033[0;32m""Executable file is ready to use""\033[0m"

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:
	@rm -f ${OBJ} ${D_FILES}
	@echo "\033[0;33m""All .o and .d files deleted""\033[0m"

fclean: clean
	@rm -f ${NAME}
	@echo "\033[0;33m""Executable file deleted""\033[0m"

re: fclean all

.PHONY: all clean fclean re
