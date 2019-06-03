/* execute.c - code used by small shell to execute commands */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>
#include	<fcntl.h>

int execute(char *argv[], int maxCom, int skips[], char *redirect[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors

 */
{
	int	pid ;
	int	child_info = -1;

	if ( argv[0] == NULL ) {		/* nothing succeeds	*/
		return 0;
	}

	//Testable pids for parent and children
	int child = 0;
	int i = 0;
	int prev_pipe[2];
	int new_pipe[2];
	for(i; i < maxCom; i++) {
		//Create a new pipe
		if (i != maxCom - 1) //Not the final command
		{
			pipe(new_pipe);
		}

		//Forks and checks for errors
		child = fork();
		if(child < 0) {
			printf("Error");
		}

		if(child != 0){
			//Parent
			wait(NULL);
			if(i != 0) //not first command
			{
				//close prev_pipe
				close(prev_pipe[0]);
				//close(prev_pipe[1]);
			}
			if(i != maxCom - 1) //not final command
			{
				//prev_pipe = new_pipe
				prev_pipe[0] = new_pipe[0];
				prev_pipe[1] = new_pipe[1];
				close(prev_pipe[1]);
			}
		}
		else
		{
			//Child
			if(i != 0) //not first command
			{
				//redirect input to prev_pipe
				dup2 (prev_pipe[0], 0);
				close(prev_pipe[0]);
			}
			if(i != maxCom - 1) //not final command
			{
				//redirect output to new_pipe
				dup2(new_pipe[1], 1);
				close(new_pipe[1]);
			}

			//redirect if < or >
			//Redirect stdin to file
			if(redirect[0] != NULL && i == 0)
			{
				int filefd_in = open(redirect[0], O_RDONLY, 0);
				dup2 (filefd_in, 0);
			}
			//Redirect stdout to file
			if(redirect[1] != NULL && i == maxCom - 1)
			{
				int filefd_out = open(redirect[1], O_WRONLY | O_CREAT, 0644);
				dup2 (filefd_out, 1);
			}

			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			//Reads current command and moves null term array to follow command
			execvp(argv[skips[i]], &argv[skips[i]]);
			perror("cannot execute command");
			exit(1);

		}



	}

	return child_info;
}
