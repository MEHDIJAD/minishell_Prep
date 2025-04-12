#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *getcwd(char *buf, size_t size);

int main(void)
{
    char *current_directory;
    
    current_directory = getcwd(NULL, 0);
    if (!current_directory){
        perror("getcwd error");
        return (EXIT_FAILURE);
    }
    printf("current_directory: %s\n", current_directory);
    free(current_directory);
    return (0);
}