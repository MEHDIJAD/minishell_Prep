#include <stdio.h>
#include <unistd.h> // For access()
#include <errno.h>
#include <string.h> // For strerror()

int main()
{
    const char *file_executable = "/bin/ls";
    const char *file_readable = "/etc/passwd";
    const char *file_nonexistent = "/tmp/no_such_file_here";
    const char *directory = "/tmp";

    printf("Checking access for: %s\n", file_executable);

    // Check existence
    if (access(file_executable, F_OK) == 0) {
        printf("  Exists? Yes.\n");

        // Check read permission
        if (access(file_executable, R_OK) == 0) {
            printf("  Readable? Yes.\n");
        } else {
            printf("  Readable? No. (%s)\n", strerror(errno));
        }

        // Check write permission
        if (access(file_executable, W_OK) == 0) {
            printf("  Writable? Yes.\n");
        } else {
            printf("  Writable? No. (%s)\n", strerror(errno)); // Likely EACCES
        }

        // Check execute permission
        if (access(file_executable, X_OK) == 0) {
            printf("  Executable? Yes.\n");
        } else {
            printf("  Executable? No. (%s)\n", strerror(errno));
        }
    } else {
        printf("  Exists? No. (%s)\n", strerror(errno)); // Likely ENOENT
    }

    printf("\nChecking execute access for: %s\n", file_readable);
    if (access(file_readable, X_OK) == -1) {
        printf("  Cannot execute %s: %s\n", file_readable, strerror(errno)); // Likely EACCES
    } else {
         printf("  Can execute %s (unexpected!).\n", file_readable);
    }


    printf("\nChecking existence for: %s\n", file_nonexistent);
     if (access(file_nonexistent, F_OK) == -1) {
        printf("  File %s does not exist: %s\n", file_nonexistent, strerror(errno)); // Likely ENOENT
    } else {
         printf("  File %s exists (unexpected!).\n", file_nonexistent);
    }

     printf("\nChecking search permission for directory: %s\n", directory);
      if (access(directory, X_OK) == 0) {
        printf("  Can search directory %s.\n", directory);
    } else {
         printf("  Cannot search directory %s: %s\n", directory, strerror(errno));
    }


    return 0;
}
