#include "shell.h"

/**
 * setEnvironmentVariable - This function Sets or modifies an environment variable.
 * @variable: This is the name of the environment variable.
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
 * unsetEnvironmentVariable - Function that Unsets an environment variable.
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
 * changeDirectory - Function that Changes the current working directory.
 * @path: This is the path to the directory to change to.
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
