#include "proj4.h"
/*author: Christian Miljkovic */

/*This program runs a shell script that takes normal commands
such as cd, ls, exit, and background processing. Furthermore, this shell
does not allow ctrl+c to exit the shell script.*/
int main()
{
	//install the handler so that we catch the SIGINT signal
	signal(SIGINT, sigint_handler);
	
    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput(  ) != EOF ) {

        procline();
    }
    return 0;
}

/*Bug 4 Fix*/
/*This is the handler that deals with the SIGINT signal. We have decided
to do nothing when the signal is caught thus prevent ctrl+c from exiting the shell.*/
void sigint_handler() {

	return;
}

/*Bug 1 Fix (procline.c Lines: 9-12)
The bug that needed to be fixed was that narg in procline.c
was not initialized therefore when it ran through the swtich statement
it would be intitliazed to MAX_ARG, therefore, since procline.c is run multiple times
and a new process is created, narg stays at this value and then does not
allow us to take in more arguments in the next iteration (or next command)*/

/*Bug 2 Fix (runcommand.c Lines: 17-64)
This bug was fixed through a series of if-else statements. The first
if statement checks to see if the second argument is NULL or an empty string
if that is the case then we get the enviroment of HOME and change the directory to HOME.
If we find that the second argument is not NULL, then we proceed to check if there is a '/',
'..', or a full path. If we realize that it is just the name of a directory we use realpath() function
to get the real path and change to that directory. If we see that it is '..' then we change the directory 
to the parent directory. */

/*Bug 3 Fix (runcommand.c Lines:70-74) 
Here we use an else if statement to catch if the user inupts 'exit' as the second argument. If
we find that it is, then we exit the shell using the exit(0) function.
*/

/*Bug 4 Fix (proj4.h & proj4.c Lines: 11 and 23-26 & 44) 
Here we needed to create a handler that did not do anything once it caught the 
signal. Therefore, we create the handler within proj4.c and then install it within 
the main function so that whenever the process recieves a SIGINT signal it simply catches it
and does nothing to the process.
*/

/*Bug 5 Fix (Line:103) 
The bug was that on lines 95-98 we do not know for sure whether we will get the
parent process or the child process, therefore, we would not know whether the child process
is reaped. Thus, by adding the wait(NULL) the parent process will wait no matter what for the child process
to change states (terminate) and then reaps it. Thus, allowing us to have the background (parent) process
will wait until the foreground (child) process finishes. 
*/
