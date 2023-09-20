#include "shell.h"

/**
 * setEnvironmentVariable - Set or modify an environment variable.
 * @variable: The name of the environment variable.
 * @value: The value to assign to the environment variable.
 *
 */
void setEnvironmentVariable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * unsetEnvironmentVariable - Unset an environment variable.
 * @variable: The name of the environment variable to unset.
 *
 */
void unsetEnvironmentVariable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
	}
}
/**
 * changeDirectory - Change the current working directory.
 * @path: The path to the directory to change to.
 *
 */
void changeDirectory(const char *path)
{
	char *oldpwd = getenv("PWD");
	char cwd[MAX_COMMAND_LENGTH];

	if (path == NULL || strcmp(path, "~") == 0)
	{
		path = getenv("HOME");
	}
	else if (strcmp(path, "-") == 0)
	{
		path = oldpwd;
	}
	if (chdir(path) != 0)
	{
		perror("cd");
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setEnvironmentVariable("PWD", cwd);
		setEnvironmentVariable("OLDPWD", oldpwd);
	}
}
