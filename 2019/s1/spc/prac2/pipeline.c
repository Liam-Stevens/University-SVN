#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    char line[255];
    char commandList[100][255];
    char commandFilter[100][100][255];
    int maxCom = 0;
    int numArg[100];

    //Reads in from stdin
    while(maxCom < 100)
    {
        //Gets the line and removes the end of line character
        fgets(line, 255, stdin);
        strtok(line,"\n");
        //Ends if it reaches the end of file
        if(feof(stdin) != 0)
        {
            break;
        }

        //Saves line to command list
        strcpy(commandList[maxCom], line);

        int i = 0;
        for(i = 0; i < 255; i++)
        {
            if(commandList[maxCom][i] == ' ')
            {
                numArg[maxCom]++;
            }
        }

        //Adds original command to new array
        char * buf = strtok(commandList[maxCom], " ");
        strcpy(commandFilter[maxCom][0], buf);

        //Adds arguments to array
        for (i = 1; i < numArg[maxCom]+1; i++){

            buf = strtok(NULL," ");
            strcpy(commandFilter[maxCom][i], buf);
        }

        maxCom++;

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

            //Execute command using new_pipe
            //Massive If statements needed because execvp does not work
            if(numArg[i] == 0)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], NULL);
            }
            else if(numArg[i] == 1)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], NULL);
            }
            else if(numArg[i] == 2)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], NULL);
            }
            else if(numArg[i] == 3)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], NULL);
            }
            else if(numArg[i] == 4)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], NULL);
            }
            else if(numArg[i] == 5)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], NULL);
            }
            else if(numArg[i] == 6)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], commandFilter[i][6], NULL);
            }
            else if(numArg[i] == 7)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], commandFilter[i][6], commandFilter[i][7], NULL);
            }
            else if(numArg[i] == 8)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], commandFilter[i][6], commandFilter[i][7], commandFilter[i][8], NULL);
            }
            else if(numArg[i] == 9)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], commandFilter[i][6], commandFilter[i][7], commandFilter[i][8], commandFilter[i][9], NULL);
            }
            else if(numArg[i] == 10)
            {
                execlp(commandFilter[i][0],commandFilter[i][0], commandFilter[i][1], commandFilter[i][2], commandFilter[i][3], commandFilter[i][4], commandFilter[i][5], commandFilter[i][6], commandFilter[i][7], commandFilter[i][8], commandFilter[i][9], commandFilter[i][10], NULL);
            }
            //Breaks incase none of these are true
            break;
        }
    }

    return 0;
}
