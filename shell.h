#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

# define length_of_input 200

void cue();
void exec_cmd(char *cmd);
char *c_e();

#endif
