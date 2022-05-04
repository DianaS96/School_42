NAME_S	= server

NAME_C	= client

NAME_B_S	= server_bonus

NAME_B_C	= client_bonus

SRC_S	= main_server.c minitalk_utils.c

SRC_C	= main_client.c minitalk_utils.c

SRC_B_S	= main_server_bonus.c minitalk_utils.c

SRC_B_C	= main_client_bonus.c minitalk_utils.c

OBJ_S	= main_server.o minitalk_utils.o 

OBJ_C	= main_client.o minitalk_utils.o

OBJ_B_S	= main_server_bonus.o minitalk_utils.o

OBJ_B_C = main_client_bonus.o minitalk_utils.o

D_FILES	= main_client.d main_server.d minitalk_utils.d

D_FILES_B   = main_client_bonus.d main_server_bonus.d minitalk_utils.d

HEADER	= minitalk.h

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

# Telling that "fclean, clean, re and all" are names of rules (not names of files)
.PHONY: fclean clean all re

all: ${NAME_S} ${NAME_C}

# $@ will be replaced by target (NAME of program)
${NAME_S}: ${OBJ_S} ${SRC_S}
	${CC} ${CFLAGS} ${OBJ_S} -o $@
	@echo "\033[0;35m""Executable file server created""\033[0m"

${NAME_C}: ${OBJ_C} ${SRC_C}
	${CC} ${CFLAGS} ${OBJ_C} -o $@
	@echo "\033[0;35m""Executable file client created""\033[0m"

bonus: ${NAME_B_S} ${NAME_B_C}

${NAME_B_S}: ${OBJ_B_S} ${SRC_B_S}
	${CC} ${CFLAGS} ${OBJ_B_S} -o $@
	@echo "\033[0;36m""Executable file server_bonus created""\033[0m"

${NAME_B_C}: ${OBJ_B_C} ${SRC_B_C}
	${CC} ${CFLAGS} ${OBJ_B_C} -o $@
	@echo "\033[0;36m""Executable file client_bonus created""\033[0m"

# $< will be replaced by first dependency (.c files)
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -MD
include ${wildcard *.d}

# Remove all ".o" and ".d" files
clean: 
	@rm -f ${OBJ_S} ${OBJ_C} ${OBJ_B_S} ${OBJ_B_C} ${D_FILES} ${D_FILES_B} 
	@echo "\033[0;33m""All .o and .d files deleted""\033[0m"
# Remove executable file and call clean cmd
fclean: clean
	@rm -f ${NAME_S} ${NAME_C} ${NAME_B_S} ${NAME_B_C}
	@echo "\033[0;33m""Executable files deleted""\033[0m"
re: fclean all
