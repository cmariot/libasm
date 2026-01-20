#include "libasm.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int test_strcpy(void)
{

    printf("\n\nTEST STRCPY\n");

    const char *sources[] = {
        "",
        "a",
        "abc",
        "bonjour",
        "hello\0hidden",
    };

    char *ret;
    char *ft_ret;
    char *dest = malloc(sizeof(char) * 100);
    char *ft_dest = malloc(sizeof(char) * 100);

    if (!dest || !ft_dest)
    {
        printf("Malloc error\n");
        return (1);
    }

    for (size_t i = 0; i < sizeof(sources)/sizeof(sources[0]); i++) {

        ft_ret = ft_strcpy(ft_dest, sources[i]);
        ret = strcpy(dest, sources[i]);

        printf(
            "test[%zu] \"%s\" => ft_dest=%s, dest=%s, ft_ret=%s, ret=%s\n",
            i, sources[i], ft_dest, dest, ft_ret, ret
        );

        assert(strcmp(ret, ft_ret) == 0);
        assert(strcmp(dest, ft_dest) == 0);
    }

    free(dest);
    free(ft_dest);

}