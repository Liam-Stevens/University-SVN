#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(char **piped)
{
    char line[256];
    char commandList[100][256];
    int maxCom = 0;
    //Reads in from stdin
    while(maxCom < 100)
    {
        fgets(line, 256, stdin);
        //Ends if it reaches the end of file
        if(feof(stdin) != 0)
        {
            break;
        }

        //Saves line to command list
        int i = 0;
        for(i; i < 256; i++)
        {
            commandList[maxCom][i] = line[i];
        }
        maxCom++;
    }

    //Testable pids for parent and children
    int child = 0;
    int in = 0;
    int childList[maxCom];
    int i = 0;
    int pipes[2];
    int length;
    for(i; i < maxCom; i++) {
        //Create a new pipe
        if (i != maxCom - 1) //Not the final command
        {
            pipe(pipes);
        }

        //Forks and checks for errors
        child = fork();
        if(child < 0) {
            printf("Error");
        }

        length = strlen(commandList[i]);
        if(child != 0){
            wait(NULL);
            if(i != 0) //not first command
            {
                //close prev_pipe
                close(pipes[0]);
            }
            if(i != maxCom - 1) //not final command
            {
                //prev_pipe = new_pipe
                pipes[0] = pipes[1];
            }
        }
        else
        {
            if(i != 0) //not first command
            {
                //redirect input to prev_pipe
                //write(pipes[0], commandList[i], length);
                dup2 (in, 0);
                close (in);
            }
            if(i != maxCom - 1) //not final command
            {
                //redirect output to new_pipe
                //write(pipes[1], commandList[i], length);
                //dup2(pipes[1], 1);
            }
            if (pipes [1] != 1)
              {
                dup2 (pipes [1], 1);
                close (pipes [1]);
              }
            //Execute command using pipes
            /*
            if(i == maxCom - 1)
            {
                dup2(pipes[1], 1);
            } */

            printf("{(%d): %d %d }", i+1, pipes[0], pipes[1]);
            printf("{%s}", commandList[i]);
            execlp(commandList[i],commandList[i], NULL);
            break;
        }
    }

    //Close all pipes and clean up

    return 0;
}
