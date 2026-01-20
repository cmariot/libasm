#include "libasm.h"
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int test_read(void)
{
    printf("\n\nTEST READ\n");

    char ft_buf[100];
    char buf[100];

    ssize_t ft_ret = ft_read(0, ft_buf, 100);

    // Open a file
    int fd = open("./tmp.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd == -1)
    {
        printf("Bad fd\n");
        return (1);
    }
    // write in the file
    ssize_t nb_write = write(fd, ft_buf, ft_ret);

    lseek(fd, 0, SEEK_SET);

    ssize_t ret = read(fd, buf, nb_write);

    if (ft_ret == -1 && ret == -1)
    {
        perror("ft_write");
        perror("write");
    }
    else if (ft_ret == -1 || ret == -1) {
        printf("Error, perror not correctly set\n");
        if (ft_ret == -1)
            perror("ft_write");
        else
            perror("write");
    }

    printf("Returned value : ft:%zd vs real:%zd\n", ft_ret, ret);
    assert(ft_ret == ret);

    // bad fd
    {
        int ret = read(-1, buf, 100);
        int ft_ret = ft_read(-1, ft_buf, 100);

        if (ret == -1 && ft_ret == -1){
            perror("ft_read");
            printf("OK\n");
        }
        else {
            printf("KO, bad fd error");
        }
    }

    // read size of 0
    {
        int ret = read(0, buf, 0);
        int ft_ret = ft_read(0, ft_buf, 0);

        if (ret != 0 || ft_ret != 0)
            printf("Should return 0\n");
    }

    // bad address
    {
        lseek(fd, 0, SEEK_SET);

        int ret = read(fd, NULL + 1, 10);
        int ft_ret = ft_read(fd, NULL + 1, 10);

        if (ret == -1 && ft_ret == -1){
            perror("ft_read");
            printf("OK\n");
        }
        else {
            printf("KO, bad address error");
        }

    }
}