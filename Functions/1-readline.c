#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>

/*
    * to compile: clang -o readline_program readline.c -lreadline -lncurses 
    ^ Prototype: char *readline(const char *)
    ! Return: returns the text of the line read.
    ! The line returned is allocated with malloc(3); the caller must free it when finished.

*/

int main(void)
{
    char *line;

    while((line = readline("minishell>"))){
        if (line && *line){
            add_history(line);
            //~ To save the command line the user just typed into the command history.(use up/down arraow keys)
        }
        free(line);
        line = NULL; //~ Good practice to reset pointer after freeing
    }
    return (0);
}