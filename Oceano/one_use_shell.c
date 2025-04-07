#include "cell.h"

//! int execvp(const char *file, char *const argv[]);

int main(int ac, char **av)
{
    (void)ac;
    int status;

    //* child process
    if (fork() == 0)
    {
        /*
        * replace the current process img with a new process img
        * in execvp: v for "vector" and p for "path".
        *  takes an array of arg and uses path to find the excutable.
        * char **av(av + 1) = {"ls", "-la", NULL};
        * + 1: to pass ./a.out
        * execvp("ls", av); 
        */
        execvp(av[1], av + 1);
    }
    wait(&status);
    //* so the parent process will wait for child

    return (EXIT_SUCCESS);
}