#include "libasm.h"
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

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

    // write in a file
    {
        int fd = open("./ft_write.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
        if (fd == -1)
        {
            printf("Can't create the ft_write.txt file\n");
            return (1);
        }
        char buf[11]= "4242424242\0";
        ssize_t nb_write = ft_write(fd, buf, 11);
        lseek(fd, 0, SEEK_SET);
        char read_buf[100];
        bzero(&read_buf, 100);
        ssize_t ret = read(fd, read_buf, nb_write);
        if (strcmp(buf, read_buf) != 0)
        {
            printf("FT : Buf and read_buf are differents, KO\n");
            printf("%s vs %s\n", buf, read_buf);
        }
        close(fd);

        fd = open("./real_write.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
        if (fd == -1)
        {
            printf("Can't create the ft_write.txt file\n");
            return (1);
        }
        nb_write = write(fd, buf, 11);
        lseek(fd, 0, SEEK_SET);
        char real_read_buf[100];
        bzero(&real_read_buf, 100);
        ret = read(fd, real_read_buf, nb_write);
        if (strcmp(buf, real_read_buf) != 0)
        {
            printf("REAL : Buf and read_buf are differents, KO\n");
            printf("%s vs %s\n", buf, real_read_buf);
        }
        close(fd);
    }

}