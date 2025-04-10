#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> 
#include <readline/readline.h>
#include <readline/history.h>

void handle_sigint(int sig) {
    (void)sig;
     write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();        
    rl_replace_line("", 0); 
    rl_redisplay();
}

int main(void) {
    char *line;
    signal(SIGINT, handle_sigint);
    while ((line = readline("minishell$ ")) != NULL) {
        if (*line){
        add_history(line);
        } 
        free(line);
    }
    return 0;
}