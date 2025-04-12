#include <stdlib.h>
#include <stdio.h>

//^ char *getenv(const char *name);

int main()
{
    const char *path_val = getenv("PATH");
    const char *user_val = getenv("USER");
    const char *term_val = getenv("TERM");
    const char *no_such_var = getenv("NOSUCHVAR");

    if (path_val != NULL) {
        printf("PATH = %s\n", path_val);
    } else {
        printf("PATH not found.\n");
    }

    if (user_val != NULL) {
        printf("USER = %s\n", user_val);
    } else {
        printf("USER not found.\n");
    }

     if (term_val != NULL) {
        printf("TERM = %s\n", term_val);
    } else {
        printf("TERM not found.\n");
    }

    if (no_such_var == NULL) {
        printf("NOSUCHVARIABLE was not found (as expected).\n");
    } else {
        printf("NOSUCHVARIABLE = %s (unexpected!)\n", no_such_var);
    }
    return 0;
}