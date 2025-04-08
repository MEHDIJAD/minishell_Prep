#include "cell.h"

/*
* 1- getline();
* 2- feof();
*/

/*
* like in argv
* ls -la file
* tokens -->[ls]
*        -->[-la]
*        -->[file]                            
*/
char **cell_split_line(char *line)
{
    char **tokens;
    unsigned int position;
    size_t bufsize;

    bufsize = BUFSIZ;
    tokens = Malloc(bufsize * sizeof(*tokens));
    position = 0;
    for(char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
        if (position >= bufsize){
            bufsize *= 2;
            tokens = Realloc(tokens, bufsize * sizeof(*tokens));
        }
    }
    tokens[position] = NULL;
    return (tokens);
}
char *cell_read_line(void)
{
    char *buf;
    size_t bufsize;
    char cwd[BUFSIZ];

    buf = NULL;
    /*
    * getline() expects the pointer *buf to either be NULL (so it allocates memory itself)
    * OR point to a pre-allocated buffer.
    */
    Getcwd(cwd, sizeof(cwd));
    printf(C"%s"RST"$>", cwd);
    if (getline(&buf, &bufsize, stdin) == -1)
    {
        free(buf);
        buf = NULL;
        /*
        * to make sure the function doesn't return a pointer to 
        * invalid or uninitialized memory.
        */
        if (feof(stdin)) {
            //* feof — check end-of-file indicator on a stream
            printf(RED"[EOF]\n"RST);
        }
        else
            printf(RED"Getline  function FAILED\n"RST);
    }
    return (buf);
}

int main(int ac, char **av)
{
    /*
    * REPEL
    * READ->EVALUATE->PRINT/EXCUTE->LOOP
    * 1️⃣ prompt + get line ✅
    * 2️⃣
    */
   char *line;
   char **args;

   while ((line = cell_read_line())) //* while line != NULL -> != 0 -> !false = true
   {
        args = cell_split_line(line);
        for (int i = 0; args[i]; ++i){
            printf("%s\n", args[i]);
        }
        /*
        * 3️⃣exec
        * 4️⃣ free
        */
       free(line);
       free(args);
   }
   return (EXIT_SUCCESS);
}