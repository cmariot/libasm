#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>

size_t ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);


int main(void) {

    // const char *tests[] = {
    //     "",
    //     "a",
    //     "abc",
    //     "bonjour",
    //     "hello\0hidden",   // strlen doit s'arrêter au \0
    // };

    // for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
    //     size_t ref = strlen(tests[i]);
    //     size_t got = ft_strlen(tests[i]);
    //     printf("test[%zu] \"%s\" => ft=%zu, ref=%zu\n", i, tests[i], got, ref);
    //     assert(got == ref);
    // }

    // puts("OK");

    // const char *s1 = "\x80";
    // const char *s2 = "\x7F";

    // printf("s1 = %s\n", s1);
    // printf("s2 = %s\n", s2);
    // printf("strcmp = %d\n", strcmp(s1, s2));
    // printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));


    // char *src = strdup("hello");
    // char *dest = malloc(sizeof(char) * 6);
    // dest[0] = 'a';

    // printf("src = %s\n", src);
    // printf("dest = %s\n", dest);
    // printf("strcpy = %s\n", strcpy(dest, src));
    // printf("ft_strcpy = %s\n", ft_strcpy(dest, src));

    // free(src);
    // free(dest);

    // char *test = ft_strdup("abc");
    // char *real = strdup("abc");

    // if (test && real)
    // {
    //     printf("ft_strdup = %s\n", test);
    //     printf("strdup    = %s\n", real);

    //     if (ft_strcmp(test, real))
    //         printf("ERROR: diff in strdup\n");

    //     free(test);
    //     free(real);
    // }
    // else
    // {
    //     printf("!str\n");
    // }

    // ssize_t ret = ft_write(-1, "hello\n", 6);
    // printf("Returned value : %zd\n", ret);
    // if (ret == -1)
    //     perror("ft_write");

    char *buf = malloc(sizeof(char) * 100);
    bzero(buf, 100);

    ssize_t ret = ft_read(0, buf, 10);
    if (ret == -1)
        perror("ft_read");
    else
        printf("BUF = %s\n", buf);

    return 0;
}
