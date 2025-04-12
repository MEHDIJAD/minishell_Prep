#include <string.h>

char *strerror(int errnum);

#include <stdio.h>
#include <string.h> // For strerror()
#include <errno.h>  // For errno and ENOENT

int main() {
    // Get the error message string for "No such file or directory"
    char *error_message = strerror(ENOENT); // ENOENT is defined in errno.h

    // Print the message
    printf("The error message for ENOENT is: %s\n", error_message);

    return 0;
}