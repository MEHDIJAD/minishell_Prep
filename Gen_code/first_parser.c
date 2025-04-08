#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct command_table
{
    char *cmd;
    char *cmd_arg;
    char  *std_input;
    char  *std_output;
} cmd_t;

void ft_parser(char *input, cmd_t *data)
{
    int i = 0;
    int j = 0;

    while (input[i] == ' ')
        i++;
    data->cmd = malloc(100);
    data->cmd_arg = malloc(100);
    while (input[i] != ' ' && input[i] != '\0')
        data->cmd[j++] = input[i++];
    data->cmd[j] = '\0';
    while (input[i] == ' ')
        i++;
    j = 0;
    while (input[i] != ' ' && input[i] != '\0')
        data->cmd_arg[j++] = input[i++];
    data->cmd_arg[j] = '\0';
}
int main(int ac, char **av)
{
    if (ac < 2)
    {
        printf("Usage: ./a.out \"command arg\"\n");
        return 1;
    }
    cmd_t data;
    ft_parser(av[1], &data);
    printf("Command: %s\n", data.cmd);
    printf("Arg: %s\n", data.cmd_arg);

    free(data.cmd);
    free(data.cmd_arg);
}
