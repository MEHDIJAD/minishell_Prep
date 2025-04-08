#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *rl;
    rl = readline("minishell> ");
    if (rl)
    {
        printf("%s\n", rl);
        free(rl);
    }
    return (0);
}