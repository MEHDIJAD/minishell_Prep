#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(void) {
    char *line;

    while ((line = readline("hist> "))) 
    {
        if (*line) {
            if (strcmp(line, "clearhist") == 0) {
                printf("Clearing history...\n");
                rl_clear_history();
            } else {
                add_history(line);
            }
        } 
        else {
             printf("Empty line entered.\n");
        }
        free(line);
        line = NULL;
    }
    rl_clear_history();
    return 0;
}