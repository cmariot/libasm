#include "libasm.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int test_strcmp(void)
{

    printf("\n\nTEST STRCMP\n");

    const char *sources[] = {
        "b",
        "a",
        "abc",
        "bonjour",
        "hello\0hidden",
    };

    // Tests for the same string
    for (size_t i = 0; i < sizeof(sources)/sizeof(sources[0]); i++) {

        int ft_ret = ft_strcmp(sources[i], sources[i]);
        int ret = strcmp(sources[i], sources[i]);

        printf(
            "test[%zu] \"%s\" vs \"%s\" => ft=%d, ref=%d\n",
            i, sources[i], sources[i], ft_ret, ret
        );

        assert(ret == ft_ret);
    }

    const char *diff_sources[] = {
        "v",
        "adsdf",
        "abfsdfc",
        "",
        "hegdfllo\0higggdden",
    };

    // Tests with different strings
    for (size_t i = 0; i < sizeof(sources)/sizeof(sources[0]); i++) {

        int ft_ret = ft_strcmp(sources[i], diff_sources[i]);
        int ret = strcmp(sources[i], diff_sources[i]);

        printf(
            "test[%zu] \"%s\" vs \"%s\" => ft=%d, ref=%d\n",
            i, sources[i], diff_sources[i], ft_ret, ret
        );

        assert(ret != 0);
    }

}