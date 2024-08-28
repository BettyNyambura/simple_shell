#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int _strlen(char *str);
char *readInput(char **linebuffer, size_t *buffersize);
int _strCmp(const char *str1, const char *str2);
char *pathFinder(char *command);
char *strDup(char *str);
char *strCpy(char *dest, char *src);
char *strCat(char *str2, char *str1);
int _toka(char **args);
void shell_executor(char *buffer);
void signalHandler(int signalnum __attribute__((unused)));
void parse_arguments(char *buffer, char **args);
void execute_command(char *path, char **args);
void signalHandler(int signalnum);

#endif
