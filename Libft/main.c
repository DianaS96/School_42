
#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//void f(unsigned int i, char* s);

int main(void)
{
   /* char var1 = 'a';
    char var2 = '1';
    //char var3 = ' ';

    printf("%i", ft_isalpha((int)var1));
    printf("%i", ft_isalpha((int)var2));
   */
    //printf("%i", ft_isdigit((int)var1));
    //printf("%i", ft_isdigit((int)var2));
   
    //printf("%i", ft_isalnum((int)var1));
    //printf("%i", ft_isalnum((int)var2));
    //printf("%i", ft_isalnum((int)var3));
   
    //printf("%i", ft_isascii((int)""));
    //printf("%i", ft_isascii((int)var1));
    //printf("%i", ft_isascii((int)var2));
    //printf("%i", ft_isascii((int)var3));

    /*printf("%i", ft_isprint((int)var1));
    printf("%i", ft_isprint((int)var2));
    printf("%i", ft_isprint((int)var3));
    printf("%i", ft_isprint((int)'\0'));*/

    /*printf("%i", ft_strlen("Meow"));
    printf("%i", ft_strlen("Hellow, World!"));*/

/*    printf("%c", (char)ft_toupper((int)'a'));
    printf("%c", (char)ft_toupper((int)'A'));
    printf("%c", (char)ft_toupper((int)'.'));*/

 /*   printf("%c", (char)ft_tolower((int)'A'));
    printf("%c", (char)ft_tolower((int)'b'));
    printf("%c", (char)ft_tolower((int)'.'));*/

/*
    printf("%i", ft_atoi("123456789"));
    printf("%i", ft_atoi("-6789"));
    printf("%i", ft_atoi("  -+123456789"));
    printf("%i", ft_atoi("  +123456789"));
*/

   /* const char str[] = "tripouille";
    //const char ch = 'a';
    printf("%s\n", ft_strchr(str, 0));
    printf("%s\n", strchr(str, 0));
	*/

    /*const char *str2 = "\0";
    //const char ch2 = 'p';
    printf("%s\n", ft_strchr(str2, 'a'));
    printf("%s\n", strchr(str2, 'a'));
*/

    /*char str[] = "";
    //const char ch = 'p';
    printf("%s\n", ft_strrchr(str, '\0'));
    printf("%s\n", strrchr(str, '\0'));
*/
    /*const char str2[] = "Computerp";
    const char ch2 = 'a';
    printf("%s\n", ft_strrchr(str2, 0));
    printf("%s\n", strrchr(str2, 0));*/

    
/*    unsigned char str[] = "Computerpi";
    printf("%s\n", (char *)ft_memset(str, '1', 3));
    unsigned char str1[] = "Computerpi";
    printf("%s\n", (char *)memset(str1, '1', 3));

    unsigned char str2[] = "Computerpi";
    printf("%s\n", (char *)ft_memset(str2, '1', 20));
    unsigned char str3[] = "Computerpi";
    printf("%s\n", (char *)memset(str3, '1', 20));*/

   /*unsigned char str[] = "Computerpi";
    ft_bzero(str, (size_t) 1);
    printf("%s\n", str);
    unsigned char str1[] = "Computerpi";
    bzero((void *)str1, (size_t)3);
    printf("%s\n", str1);*/

    /*unsigned char str2[] = "Computerpi";
    printf("%s\n", (char *)ft_bzero(str2, 20));
    unsigned char str3[] = "Computerpi";
    printf("%s\n", (char *)bzero(str3, 20));*/

    /*unsigned char src[10] = "1234567890";
    unsigned char dst[5] = ""; 
    ft_memcpy(dst, src, 6);
    printf("%s\n", dst);

    unsigned char src1[10] = "1234567890";
    unsigned char dst1[5] = ""; 
    memcpy(dst1, src1, 6);
    printf("%s\n", dst1);*/

	/*char src[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = {0, 0, 0, 0, 0, 0, 0};
	printf("%s\n", (char *)ft_memmove(s0, src, 7));
	
	char src1[] = {65, 66, 67, 68, 69, 0, 45};
    char s1[] = {0, 0, 0, 0, 0, 0, 0};
    printf("%s",(char *) memmove(s1, src1, 7));
*/
	/*unsigned char src[10] = "\0";
	printf("%s\n", ft_memmove(src, src[3], 3));
	unsigned char s[10] = "\0";
	printf("%s", memmove(&s[4], &s[3], 3));
    */
	
	/*char    str[] = "1234567890";
    char *istr = ft_strdup(str);
    printf("%s", istr);
    free(istr);*/

    /*char dst[30];
    char src[] = "oucou!";
    printf("%zu\n", ft_strlcpy(dst, src, (size_t)0));
    printf("%s", dst);
    printf("%lu", strlcpy(dst, src, 0));
   */

	//char d[15];
	//d[14] = 'a';
	//printf("%lu\n", strlcat("there is no stars in the sky", "the cake is a lie !\0I'm hidden lol\r\n", 0));
	//printf("%s\n\n", d);the cake is a lie !\0I'm hidden lol\r\n

	//char dst[15]; 
	//dst[14] = 'a';
   // char src[] = "AAAAAAAAA";
	//dst[0] = 'B';
    //printf("%zu\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", (size_t)15));
	//printf("%s\n", dst);

	//char *dest;
	//char dest[] = "rrrrrrrrrrrrrrr";
	//memset(dest, 'r', 15);
//	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
//	printf("%s\n\n", dest);
	
//	char d[] = "rrrrrrrrrrrrrrr";
  //  printf("%lu\n", strlcat(d, "lorem ipsum dolor sit amet", 5));
    //printf("%s\n", d);

	/*char dst1[30];
	char src1[] = "AAAAAAAAA";
	dst1[0] = 'B';
   	printf("\n%lu\n", strlcat(dst1, src1, 2));
	printf("%s\n", dst1);*/

   /* char    *str1 = "Tripouille";
    char    *str2 = "TripouilleX";
    printf("%i\n", ft_strncmp(str1, str2, (size_t)42));
    printf("%i\n", strncmp(str1, str2, (size_t)42));
*/
   /* unsigned char src[15] = "1234567890";
    char *sym;
    char *sym2;
    sym = ft_memchr(src, '4', 10);
    sym2 = memchr(src, '4', 10);
    printf ("%s\n", sym);
    printf ("%s", sym2);*/

    /*unsigned char src[15] = "1234557890";
    unsigned char dst[15] = "1234467890";
    printf("%i\n", ft_memcmp(src, dst, 10));
    printf("%i", memcmp(src, dst, 10));*/

    //int i = 2147483648;
    ///printf("%s\n", ft_itoa(i));

    /*int fd = open("ft_putchar_fd.txt", O_RDWR | O_CREAT);
    char    c = 'a';
    ft_putchar_fd(c, fd);
    close(fd);
    return (0);*/

    /*int fd = open("ft_putstr_fd.txt", O_RDWR | O_CREAT);
    char    *str = "Hello, World!";
    ft_putstr_fd(str, fd);
    close(fd);*/

    /*int fd = open("ft_putendl_fd.txt", O_RDWR | O_CREAT);
    char    *str = "Hello, World!";
    ft_putendl_fd(str, fd);*/

	/*int fd = open("ft_putnbr_fd.txt", O_RDWR | O_CREAT);
    int n = 5764801;
    ft_putnbr_fd(n, fd);
*/
    /*char const  *s1 = "";
    char const  *s2 = "42";
    printf("%s\n", ft_strjoin(s1, s2));
	printf("%i\n", ft_strlen(ft_strjoin(s1, s2)));
	*/

   char    *s = "      split     this for   me  !";
    char    c = ' ';
    ft_split(s, c);

	/*char const *s1 = "abcgfhjacbc";
    char const *set = "abc";
    printf("%s", ft_strtrim(s1, set));*/

    /*char const *s = "tripouille";
    unsigned int start = 100;
    size_t len = 1;
    printf("%s", ft_substr(s, start, len));*/

    /*char *m = "Meow";
    t_list *list = ft_lstnew((void *) m);
    char *b = "You";
    t_list *list1 = ft_lstnew((void *) b);
    list->next = list1;
    char *c = "Oh";
    t_list *list2 = ft_lstnew((void *) c);
    list->next->next = list2;
    // ft_lstadd_front(list->content, list1);
    // ft_lstadd_front(list->content, list2);
    // printf("%s", (char *)list->content);

    //printf("%i", ft_lstsize(list));
    printf("%s", (char *)ft_lstlast(list)->content);*/
    
    /*const char *s1 = "How are you?";
    const char *s2 = "are";
    size_t n = 3;
    printf("%s\n", ft_strnstr(s1, s2, n));
    printf("%s", strstr(s1, s2));*/

    /*char const *s = "ABCDE";
    printf("%s", ft_strmapi(s, f));*/

   /* char s[] = "ABCDE";
    ft_striteri(s, f);
    printf("%s", s);
*/
    return (0);
}

/*char f(unsigned int i, char ch)
{
    return (ch + i);
}*/

/*void f(unsigned int i, char* s)
{
    *s += i;
}*/
