#include "shell.h"

int main()
{
	char *entry;
	pid_t pid;

	while (1)
	{
		cue();
		entry = c_e();

		if (entry == NULL)
		{
			break;
		}
		if (entry[0] == '\0')
		{
			free(entry);
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			exec_cmd(entry);
		}
		else
		{
			int result;
			waitpid(pid, &result, 0);
		}

		free(entry);
	}
	return 0;
}
