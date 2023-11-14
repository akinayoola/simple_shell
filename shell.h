#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

# define length_of_input 200
#define MAX_PATH_LENGTH 500
#define MAX_ARGUMENTS 200
#define MAX_INPUT 100
#define MAX_ARGS 10

#define PROD(c) (puts(c))
#define MP(c) (write(STDOUT_FILENO, c, _afstrlen(c)))

extern char **environ;

char *_afstrtok(char *str, const char *delim);

struct Environment
{
	char *name;
	char *value;
};

void handle_commands(char *commands[], int *status);
void handle_logical_operators(char *cmdargs[], int logic_operators, int *status);
void change_directory(char *cmdargs[]);
void unset_env(char *cmdargs[]);
void set_env(char *cmdargs[]);
void executecommand(char *cmd, char *cmdargs[]);
ssize_t _afgetline(char **lineptr, size_t *n, FILE *stream);
void process_commands();
void cue();
void exec_cmd(char *cmd);
char *get_command_path(const char *cmd);
void exit_shell(char *cmdargs[]);
void print_environment();
char *c_e();
size_t _afstrlen(const char *str);
int _afstrcmp(const char *s1, const char *s2);
char *af_strdup(const char *str);
char *af_strcpy(char *dest, const char *src);
char *_afstrcat(char *dest, const char *src);
#endif
