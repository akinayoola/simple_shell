#include "shell.h"

int main()
{
	while (1)
	{
	cue();
	process_commands();
	}
	return 0;
}

void process_commands()
{
	char *entry = c_e();

	if (entry == NULL)
	{
		exit_shell();
	}
	
	if (entry[0] != '\0')
	{
		char *args[2];
		args[0] = _afstrtok(entry, " ");
		args[1] = NULL;

		if (strcmp(args[0], "exit") == 0)
		{
			free(entry);
			exit_shell();
		}
		else if (strcmp(args[0], "env") == 0)
		{
			free(entry);
			print_environment();
		}
		else
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				exec_cmd(args[0]);
				free(entry);
				_exit(EXIT_FAILURE);
			}
			else
			{
				int result;
				waitpid(pid, &result, 0);
			}
		}
	}
	free(entry);
}
