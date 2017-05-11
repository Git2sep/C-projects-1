#include "proj4.h"


/*author: Christian Miljkovic */

/*This program takes in the commands during 
the execution of a shell program. This program handles
the ls comand, cd command, and exit command, and background processing command */

// execute a command with optional wait
int runcommand(char **cline, int where) {
    pid_t pid;
    int status;

    if(strcmp(*cline, "cd") == 0) {

        /*Bud 2 Fix*/
        //get the other argument in the command line inidicating the path
        char * path = cline[1];

        //check to see if it is null or empty if so then change to the home directory
        if(path == NULL || (strcmp(path,"") == 0))

            chdir(getenv("HOME"));

        
        //now that we know it isn't empty or NULL we check whether it is ".." or a path
        else {

            //else check to see if it is the cmd to go back to the parent directory
            if(strcmp(path,"..") == 0) {

                //switch to the parent directory
                chdir(path); 
            }

            //check if we have a forward slash which gives us an indication that we have a path
            //that we do not have to concatenate later
            else if(path[0] == '/') {

                //we have a full path therefore can use just that or it is just a /
                //therefore we are brought to the root
                if((chdir(path)) != 0)

                    //in case it is invalid we handle that here
                    printf("This directory does not exist.\n");
            }

            //else we have piece together the path
            else {

                //use a buffer to hold the max len path
                char buffer[PATH_MAX + 1];
                char *real_path = realpath(path,buffer); //this gives us the path we need 
                                                        //when given just the real path name

                if((chdir(real_path) != 0))
                    
                    printf("This directory does not exist.\n");

                }
            }

            
        }


    /*Bug 3 Fix*/
    //check to see if the exit text was input and if so
    //call the exit function
    else if(strcmp(*cline, "exit") == 0) {

        exit(0);
    }

    else {

        switch(pid=fork()) {
            case -1:
                perror(SHELL_NAME);
                return (-1);
            case 0:
                execvp(*cline,cline);
                //we should never get to this code, sice execve does not return
                perror(*cline);
                exit(1);
        }


    }


    // code for parent
    // if background process print pid and exit
    // program is running in the background
    if(where == BACKGROUND) {
        printf("[Process id %d]\n",pid);
        return (0);
    }

    /*Bug Fix 5*/
    //this makes sure that the parent process waits for the 
    //child process to fully finish before it gets reaped
    wait(NULL);

    // wait until process pid exits
    if (waitpid(pid,&status,0) == -1)
        return (-1);
    else
        return (status);
}
