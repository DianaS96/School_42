NAME = libft.a

SRC = ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_isprint.c\
	  ft_strlen.c\
	  ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_strlcpy.c\
	  ft_strlcat.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strncmp.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strnstr.c\
	  ft_atoi.c\
	  ft_substr.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_itoa.c\
	  ft_calloc.c\
	  ft_strdup.c\
	  ft_strmapi.c\
	  ft_striteri.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew_bonus.c\
	  ft_lstadd_front_bonus.c\
	  ft_lstsize_bonus.c\
	  ft_lstlast_bonus.c\

SRCB = ft_lstnew_bonus.c\
      ft_lstadd_front_bonus.c\
      ft_lstsize_bonus.c\
      ft_lstlast_bonus.c\
      #ft_lstadd_back.c\
      ft_lstdelone.c\
      ft_lstclear.c\
      ft_lstiter.c\
      ft_lstmap.c
      #ft_memmove.c

INCL = libft.h

# We take SRC & SRCB files and change .c on .o
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

# Compile ".c" to ".o" files
.c.o: ${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INCL}

# Creating library
$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

bonus: ${OBJB}
	ar rc ${NAME} ${OBJ} ${OBJB}
	ranlib ${NAME}

# Remove all ".o" files
clean:
	rm -f ${OBJ}

# Remove library libft.a
fclean:
	rm -f ${NAME}

re: fclean all
