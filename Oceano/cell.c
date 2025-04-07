#include "cell.h"

char *cell_read_line(void)
{
    char *buf;
    size_t bufsize;
    char cwd[BUFSIZ];

    buf = NULL; //? getline will take care of it

    Getcwd(cwd, sizeof(cwd));
    printf(C"%s"RST"$>", cwd);

    if (getline(&buf, &bufsize, stdin) == -1)
    {
        buf = NULL;
        if (feof(stdin))
            printf(RED"[EOF]\n"RST);
        else
            printf(RED"Getline failed\n"RST);
    }
    return (buf);
}

int main(int ac, char **av)
{
    /*
    * REPEL
    * READ->EVALUATE->PRINT/EXCUTE->LOOP
    */
   char *line;

   while ((line = cell_read_line()))
   {
    //* 1- get line
    //* 2- get tokens
    //*   ->lexing->parsing EVALUATING
    //* 3- Exec

   }

   return (EXIT_SUCCESS);

}