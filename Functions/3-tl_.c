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
    // 3. (Optional but recommended) Clear the current input line buffer.
    //    This replaces whatever the user might have typed before pressing Ctrl+C
    //    with an empty string.
    rl_replace_line("", 0);
    // 4. Tell readline to redisplay the prompt and the (now empty) input line.
    rl_redisplay();
    /*
     🏁 rl_replace_line("", 0);: This function replaces the contents of readline's internal line buffer with an empty string (""). 
     The second argument 0 tells it not to clear the undo list. This ensures that if the user had typed ls -l and then pressed Ctrl+C, the ls -l text disappears from the input line.
     🏁 rl_redisplay();: This is the key function. It tells readline to redraw the current line, which includes the prompt ("minishell$ ") and the current contents of the line buffer (which we just cleared using rl_replace_line).
    */
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