#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIASES 10

// Structure to store aliases
typedef struct {
    char name[256];
    char value[256];
} Alias;

Alias aliases[MAX_ALIASES];  // Array to store aliases
int alias_count = 0;          // Counter for the number of aliases

// Function to find an alias by name
Alias *find_alias(const char *name) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            return &aliases[i];
        }
    }
    return NULL;
}

// Function to handle the alias command
void handle_alias(char *cmdargs[]) {
    // Placeholder for alias handling
    if (cmdargs[1] == NULL) {
        // Print all aliases
        for (int i = 0; i < alias_count; i++) {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
        }
    } else if (cmdargs[2] == NULL) {
        // Print the alias with the specified name
        Alias *alias = find_alias(cmdargs[1]);
        if (alias != NULL) {
            printf("%s='%s'\n", alias->name, alias->value);
        } else {
            fprintf(stderr, "Alias not found: %s\n", cmdargs[1]);
        }
    } else if (cmdargs[3] == NULL && strchr(cmdargs[1], '=')) {
        // Define or update an alias
        char *name = strtok(cmdargs[1], "=");
        char *value = strtok(NULL, "=");

        Alias *existing_alias = find_alias(name);
        if (existing_alias != NULL) {
            // Update existing alias
            strcpy(existing_alias->value, value);
        } else {
            // Define a new alias
            if (alias_count < MAX_ALIASES) {
                strcpy(aliases[alias_count].name, name);
                strcpy(aliases[alias_count].value, value);
                alias_count++;
            } else {
                fprintf(stderr, "Maximum number of aliases reached\n");
            }
        }
    } else {
        fprintf(stderr, "Usage: alias [name[='value'] ...]\n");
    }
}

// Example usage of the handle_alias function
int main() {
    // Define an alias
    char *alias_command1[] = {"alias", "myalias='ls'", NULL};
    handle_alias(alias_command1);

    // Print all aliases
    char *alias_command2[] = {"alias", NULL};
    handle_alias(alias_command2);

    // Print a specific alias
    char *alias_command3[] = {"alias", "myalias", NULL};
    handle_alias(alias_command3);

    // Update an existing alias
    char *alias_command4[] = {"alias", "myalias='ls -l'", NULL};
    handle_alias(alias_command4);

    // Print all aliases after update
    char *alias_command5[] = {"alias", NULL};
    handle_alias(alias_command5);

    // Define a new alias
    char *alias_command6[] = {"alias", "newalias='echo Hello'", NULL};
    handle_alias(alias_command6);

    // Attempt to define an alias with incorrect syntax
    char *alias_command7[] = {"alias", "invalid_syntax", NULL};
    handle_alias(alias_command7);

    return 0;
}

