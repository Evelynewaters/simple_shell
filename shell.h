#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <error.h>
#include <signal.h>

extern char **environ;
void display_prompt(void);
int read_command(char *command, int max_length);
int executeCommand(const char *command);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
char *_strncpy(char *dest, char *src, int n);
char *_strrchr(char *str, int character);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, size_t n);
int str_len(char *str);
void perform_env(char **env);
char **executeCommandsFromFile(char *filename);
void free_all(char **arr);

#endif
