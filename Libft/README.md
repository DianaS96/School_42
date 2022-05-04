# Libft :books:	
My very first library that contains the following functions:
## Part 1 - re-coded Libc functions
isalpha
• isdigit
• isalnum
• isascii
• isprint
• strlen
• memset
• bzero
• memcpy
• memmove
• strlcpy
• strlcat
• toupper
• tolower
• strchr
• strrchr
• strncmp
• memchr
• memcmp
• strnstr
• atoi
• calloc
• strdup
## Part 2 - functions that work with strings
* ft_substr (Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’)
* ft_strjoin (Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’)
* ft_strtrim (Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string)
* ft_split (Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer)
* ft_itoa (Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled)
* ft_strmapi (Applies the function ’f’ to each character of the string ’s’ , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’)
* ft_striteri (Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary)
* ft_putchar_fd (Outputs the character ’c’ to the given file descriptor)
* ft_putstr_fd (Outputs the string ’s’ to the given file descriptor)
* ft_putendl_fd (Outputs the string ’s’ to the given file descriptor, followed by a newline)
* ft_putnbr_fd (Outputs the integer ’n’ to the given file descriptor)
## Part 3 - functions to manipulate lists
* ft_lstnew (Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL)
* ft_lstadd_front (Adds the element ’new’ at the beginning of the list)
* ft_lstsize (Counts the number of elements in a list)
* ft_lstlast (Returns the last element of the list)
