#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>


extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

int checker(char **cmd, char *buffer);
void prompt_user(void);
void handle_signal(int sn);
char **tokenizer(char *input);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *input);
void exit_cmd(char **command, char *input);

void print_env(void);

int _strlen(char *str);
int _strCmp(const char *str1, const char *str2, int a);
int _strncmp(const char *str1, const char *str2);
char *strDup(char *str);
char *strCpy(char *dest, char *src);
char *strCat(char *str2, char *str1);

char *_strchr(char *s, char c);
char *test_path(char **path, char *command);

void execution(char *cmd_p, char **args);
char *find_path(void);
void free_buffers(char **buffer);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif 
