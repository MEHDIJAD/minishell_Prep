#include <stdio.h>
#include <stdlib.h> // For free()
#include <unistd.h> // For chdir(), getcwd()
#include <limits.h>

int chdir(const char *path);

int main() {
   char pwd[PATH_MAX];

   getcwd(pwd, PATH_MAX);
   printf("%s\n", pwd);
   chdir("..");
   getcwd(pwd, PATH_MAX);
   printf("%s\n", pwd);
}