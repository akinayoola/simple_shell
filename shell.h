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

extern char **environ;

char *_afstrtok(char *str, const char *delim);

struct Environment
{
	char *name;
	char *value;
};

void process_commands();
void cue();
void exec_cmd(char *cmd);
char *get_command_path(const char *cmd);
void exit_shell();
void print_environment();
char *c_e();
size_t _afstrlen(const char *str);
int _afstrcmp(const char *s1, const char *s2);
char *af_strdup(const char *str);
char *af_strcpy(char *dest, const char *src);
char *_afstrcat(char *dest, const char *src);
#endif
