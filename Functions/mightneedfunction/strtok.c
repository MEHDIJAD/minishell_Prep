#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "apple,banana,orange";
    char *token;

    token = strtok(str, ",");
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }
    return (0);  
}