#include "shell.h"
/**
 * main - main program
 * Return: 0
 */
int main(void)
{
	char *entry;
	int status = 0;

	while (1)
	{
		cue();
		entry = c_e();

		if (entry == NULL)
		{
			break;
		}
		if (entry[0] != '\0')
		{
			char *commands[10];
			int i = 0;
			char *token;

			for (token = _afstrtok(entry, ";"); token && i < 10;
					token = _afstrtok(NULL, ";"))
			{
				commands[i++] = token;
			}
			commands[i] = NULL;
			handle_commands(commands, &status);
			free(entry);
		}
	}
	return (0);
}

