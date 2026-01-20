#include "libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int test_strdup(void)
{

    printf("\n\nTEST STRDUP\n");

    const char *sources[] = {
        "",
        "a",
        "abc",
        "bonjour",
        "hello\0hidden",
    };

    // Tests for the same string
    for (size_t i = 0; i < sizeof(sources)/sizeof(sources[0]); i++) {

        char* ft_ret = ft_strdup(sources[i]);
        char* ret = strdup(sources[i]);

        if (!ft_ret && !ret) {
            printf("NULL, ok continue.\n");
            continue;
        }

        printf(
            "test[%zu] \"%s\"=> ft=%s, ref=%s\n",
            i, sources[i], ft_ret, ret
        );

        assert(strcmp(ret, ft_ret) == 0);

        free(ft_ret);
        free(ret);
    }
}