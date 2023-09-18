#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define READ_SIZE 1024
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
ssize_t custom_getline(char **buffer, size_t *buf_size);

#endif
