#ifndef SHS_H_INCLUDED
#define SHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void _ntty(char *);
void _itty(char *);
void _exec( char *, char **, char *, int *);
void _itoa(int, char *);
void _read(char **, char **, int *, char *);
char *_getenv(char *);
void ecodeinit(char **);
int _findcmd(char **, char *);
char *token_command(char *);
char **token_arguments(char *, char *);
void print_env();
void itty_free(char *, char **, char *);
void ntty_free(char *, char **, char *, char *, char *);
int _getpath(char **, char *);
void pdeniederr(int *, char *, char *, char *);
void nfounderr(int *, char *, char *, char *);

#endif
