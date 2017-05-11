/*co-author: Christian Miljkovic */

#ifndef PROJECT4_H
#define PROJECT4_H


#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h> //this is used in order to create a buffer that can 
					//take the max sized path name

#define EOL       1   /*end of line*/
#define ARG       2   /* normal arguments */
#define AMPERSAND 3
#define SEMICOLON 4
#define PONDKEY   5   /*for pondkey*/
#define PIPE      6   /*for pipe*/

#define MAXARG 512   /* max. no. command args*/
#define MAXBUF 512   /* max. length input line */

#define FOREGROUND  0
#define BACKGROUND  1

#define PROMPT  "sh201>  "
#define SHELL_NAME  "sh201"

int procline(void);

int userinput( ) ;

int gettok(char **outptr) ;

int runcommand(char **cline, int where) ;

//this declares the handler that we use to prevent ctrl+c from exiting
//the shell
void sigint_handler();


#endif // PROJECT4_H


