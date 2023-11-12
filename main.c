#include "shell.h"

int main()
{
	pid_t pid;
	char *entry;
	while (1)
	{
		cue();
		entry = c_e();
		
		if (!entry)
		{
			break;
		}
		
		if (entry[0] != '\0')
		{
			pid = fork();
			
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			else if (pid == 0)
			{
				char *token;
				char *cmdargs[10];
				int i = 0;
				for (token = _afstrtok(entry, " "); token && i < 10; token = _afstrtok(NULL, " "))
				{
					cmdargs[i++] = token;
				}
				cmdargs[i] = NULL;
				executecommand(cmdargs[0], cmdargs);
				exit(EXIT_SUCCESS);
			}
			else
			{
				int result;
				waitpid(pid, &result, 0);
			}
			free(entry);
		}
	}
	return 0;
}
