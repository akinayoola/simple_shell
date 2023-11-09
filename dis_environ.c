#include "shell.h"

void print_environment()
{
	char **env = environ;
	
	while (*env)
	{
		char *env_var = *env;
		int len = 0;

		while (env_var[len] != '\0')
		{
			len++;
		}
		write(STDOUT_FILENO, env_var, len);
		write(STDOUT_FILENO, "\n", 1);

		env++;
	}
}

char *get_command_path(const char *cmd)
{
	char *path_env;
	char *path_copy;
	char *token;
	
	if (strchr(cmd, '/'))
	{
		return strdup(cmd);
	}

	path_env = getenv("PATH");
	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char cmd_path[MAX_PATH_LENGTH];
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, cmd);

		if (access(cmd_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(cmd_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
