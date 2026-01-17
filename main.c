#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

// size_t ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);

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

    const char *s1 = "\x80";
    const char *s2 = "\x7F";

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("strcmp = %d\n", strcmp(s1, s2));
    printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));

    return 0;
}
