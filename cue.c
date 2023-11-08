#include "shell.h"

void cue()
{
	char indicator[] = "#cisfun$ ";
	write(STDOUT_FILENO, indicator, sizeof(indicator) - 1);
}
