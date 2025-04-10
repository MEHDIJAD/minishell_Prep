#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

//^ void add_history(const char *line);

int main(void)
{
    char *line;
    HIST_ENTRY **hist_list;
    int i;

    while((line = readline("minishell$ ")))
    {
        if (*line)
        {
            if(strcmp(line, "history") == 0)
            {
                hist_list = history_list();
                if (hist_list)
                {
                    for(i = 0; hist_list[i]; i++)
                        printf("%4d %s\n", i + 1, hist_list[i]->line);
                }
            } 
            else
            {
                add_history(line);
                printf("You said: %s\n", line);
            }
        }
        free(line);
    }
    printf("\nGoodbye!\n");
    return (0);
}
