#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* ☢️ in my minishell project i need to handle all spaces (\t \v ...)
*/

#define DEL " "

/*
* strtok(); extract tokens from strings
* 🅿️ :char *strtok(char *str, const char *delim);
*/

void    cell_split_line(char *line)
{
    char *tokens[6] = {0};
    int position;

    position = 0;
    for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
    }
    position = 0;
    while (tokens[position]){
        printf("[%s]\n", tokens[position++]);
    }

}

int main(void)
{
    char sh_cmd[] = "ls -la file.txt | cat"; 
    cell_split_line(sh_cmd);

    return (EXIT_SUCCESS);
}

