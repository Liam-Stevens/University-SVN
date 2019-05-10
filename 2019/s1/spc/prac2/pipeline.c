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
    //char commandList[100][256] = {{"cat"},{"grep"},{"wc"}};
    char commandList[100][255];
    //char argList[100][255] = {{"cat"},{"pipeline.c"},{0},{"grep"},{"."},{0},{"wc"},{"-l"},{0}};
    //char args[100][256] = {{"pipeline.c"},{"."},{"-l"}};
    char commandFilter[100][100][255];
    int maxCom = 0;
    int numArg[100];
    //commandList[0] = ;
    //commandList[1] = {{"sort"}};
    //maxCom = 3;
    //Reads in from stdin





    while(maxCom < 100)
    {
        fgets(line, 255, stdin);
        strtok(line,"\n");
        //Ends if it reaches the end of file
        if(feof(stdin) != 0)
        {
            break;
        }

        //Saves line to command list
        int i = 0;

        strcpy(commandList[maxCom], line);

        for(i = 0; i < 255; i++)
        {
            if(commandList[maxCom][i] == ' ')
            {
                numArg[maxCom]++;
            }
        }
        char * buf = strtok(commandList[maxCom], " ");
        strcpy(commandFilter[maxCom][0], buf);


        for (i = 1; i < numArg[maxCom]+1; i++){

            buf = strtok(NULL," ");
            strcpy(commandFilter[maxCom][i], buf);
        }
        /*
        buf = strtok(NULL," ");
        strcpy(arg1[maxCom], buf);
        buf = strtok(NULL," ");
        strcpy(arg2[maxCom], buf);
        buf = strtok(NULL," ");
        strcpy(arg3[maxCom], buf);*/
        //commandFilter[i+1] = NULL;
        //char *buf3 = NULL;
        //strcpy(commandFilter[i+1], buf3);


        printf("%s %s \n", commandFilter[maxCom][0], commandFilter[maxCom][1]);
        //printf("%d \n", maxCom);
        printf("%d \n", numArg[maxCom]);
        maxCom++;
        printf("%d \n", maxCom);
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
                close(prev_pipe[1]); //May not need to close
            }
            if(i != maxCom - 1) //not final command
            {
                //redirect output to new_pipe
                dup2(new_pipe[1], 1);
                close(new_pipe[1]);
            }
            //Execute command using new_pipe

            //printf("{(%d): %d %d }", i+1, new_pipe[0], new_pipe[1]);
            //printf("{%s}", commandList[i]);
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
            /*
            char argList2[100][255];
            int j = 0;
            for (j; j < 100; j++)
            {
                strcpy(argList2[j], argList[j]);
            } */
            //execvp(commandFilter[i][0],commandFilter[i]);
            //system(commandList[i]);
            break;
        }
    }

    //Close all new_pipe and clean up

    return 0;
}
