#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcmp in examples
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h> // For write
#include <signal.h> // For signal example

// Global flag for signal example
volatile sig_atomic_t sigint_received = 0;

void handle_sigint(int sig) {
    (void)sig;
    sigint_received = 1; // Set flag, avoid non-safe functions here
}

int main(void) {
    char *line;
    printf("--- Readline Example ---\n");
    while ((line = readline("input> "))) { // Reads line, returns new malloc'd buffer
        if (line && *line) {
            printf("Readline returned: '%s'\n", line);
            add_history(line); // Add copy to history
        } else if (line) {
            printf("Readline returned an empty line.\n");
        }
        free(line); // Free the buffer returned by readline
        line = NULL;
    }
    printf("\nReadline returned NULL (EOF likely). Exiting.\n");
    return 0;
}