#include "libasm.h"
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


int test_write(void)
{
    printf("\n\nTEST WRITE\n");

    const char *tests[] = {
        "",
        "a\n",
        "abc\n",
        "bonjour\n",
        "hello\n\0hidden",   // strlen doit s'arrêter au \0
    };

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {

        ssize_t ft_ret = ft_write(1, tests[i], strlen(tests[i]));
        ssize_t ret = write(1, tests[i], strlen(tests[i]));

        if (ft_ret == -1 && ret == -1)
            perror("ft_write");
        else if (ft_ret == -1 || ret == -1)
            printf("Error, perror not correctly set\n");

        printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
        assert(ft_ret == ret);

    }

    const char *error_tests[] = {
        "hello\0hidden\n"
    };

    // -1 FD -> BAD FD
    for (size_t i = 0; i < sizeof(error_tests)/sizeof(error_tests[0]); i++) {

        ssize_t ft_ret = ft_write(-1, error_tests[i], strlen(error_tests[i]));
        ssize_t ret = write(-1, error_tests[i], strlen(error_tests[i]));

        if (ft_ret == -1 && ret == -1) {
            perror("ft_write");
            perror("write");
        }
        else if (ft_ret == -1 || ret == -1)
            printf("Error, perror not correctly set\n");

        printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
        assert(ft_ret == ret);

    }

    // Test with a \0 inside and a size > \0 pos
    for (size_t i = 0; i < sizeof(error_tests)/sizeof(error_tests[0]); i++) {

        ssize_t ft_ret = ft_write(1, error_tests[i], 14);
        ssize_t ret = write(1, error_tests[i], 14);

        if (ft_ret == -1 && ret == -1) {
            perror("ft_write");
            perror("write");
        }
        else if (ft_ret == -1 || ret == -1)
            printf("Error, perror not correctly set\n");

        printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
        assert(ft_ret == ret);

    }

    // Write size = 0 : don't print anything, return 0
    for (size_t i = 0; i < sizeof(error_tests) / sizeof(error_tests[0]); i++)
    {

        ssize_t ft_ret = ft_write(1, error_tests[i], 0);
        ssize_t ret = write(1, error_tests[i], 0);

        if (ft_ret == -1 && ret == -1) {
            perror("ft_write");
            perror("write");
        }
        else if (ft_ret == -1 || ret == -1)
            printf(
                "Error, perror not correctly set. ft:%zd vs real:%zd\n",
                ft_ret, ret
            );

        printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
        assert(ft_ret == ret);
    }

    // Bad address
    {

        ssize_t ft_ret = ft_write(1, NULL + 1, 10);
        ssize_t ret = write(1, NULL + 1, 10);

        if (ft_ret == -1 && ret == -1) {
            perror("ft_write");
            perror("write");
        }
        else if (ft_ret == -1 || ret == -1)
            printf(
                "Error, perror not correctly set. ft:%zd vs real:%zd\n",
                ft_ret, ret
            );

        printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
        assert(ft_ret == ret);
    }

}