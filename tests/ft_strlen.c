#include "libasm.h"
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

int test_strlen(void)
{
    printf("TEST STRLEN\n");

    const char *tests[] = {
        "",
        "a",
        "abc",
        "bonjour",
        "hello\0hidden",   // strlen doit s'arrêter au \0
    };

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        size_t ref = strlen(tests[i]);
        size_t got = ft_strlen(tests[i]);
        printf("test[%zu] \"%s\" => ft=%zu, ref=%zu\n", i, tests[i], got, ref);
        assert(got == ref);
    }

}