#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    // Initialize the history list
    using_history();

    // Add some entries to the history
    add_history("First command");
    add_history("Second command");
    add_history("Third command");

    // Print the history before clearing
    printf("History before clearing:\n");
    HIST_ENTRY *entry;
    for (int i = 0; (entry = history_get(i)) != NULL; i++) {
        printf("%d: %s\n", i, entry->line);
    }

    // Clear the history
    rl_clear_history();

    // Print the history after clearing
    printf("\nHistory after clearing:\n");
    for (int i = 0; (entry = history_get(i)) != NULL; i++) {
        printf("%d: %s\n", i, entry->line);
    }

    return 0;
}
