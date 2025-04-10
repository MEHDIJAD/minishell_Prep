#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
* Function i can use:
* 1- readline
* 
*/

void handler_signal(int signum)
{
    (void)signum;
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
}

int main(void)
{
    char *line;
    struct sigaction sa;

    sa.sa_handler = handler_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL) == -1){
        perror("sigaction failed");
        exit(EXIT_FAILURE);
    }
    signal(SIGQUIT, SIG_IGN);
    while ((line = readline("minishell>")))
    {
        if (line && *line){
            add_history(line);
        }
        if (line){
            free(line); //~The pointer returned by readline is allocated with malloc and we have to free it ourselves.
            line = NULL;
        }
    }
    return (0);
}