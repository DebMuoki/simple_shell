#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main(void);
void stripNewline(char *str);
void executeCommand(char *command);
int parseArguments(char *command, char *args[]);
void printEnvironment(void);
int findCommandPath(char *command, char *full_path);
int startsWith(const char *str, const char *prefix);
ssize_t get_line(char **lineptr, size_t *n, int fd);
void changeDirectory(const char *path);
void setEnvironmentVariable(const char *variable, const char *value);
void unsetEnvironmentVariable(const char *variable);
#endif
