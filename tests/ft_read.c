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

}