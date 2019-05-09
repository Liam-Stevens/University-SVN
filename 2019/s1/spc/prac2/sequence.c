#include <stdio.h>

int main()
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
    int childList[maxCom];
    int i = 0;
    for(i; i < maxCom; i++) {
        //Forks and checks for errors
        child = fork();
        if(child < 0) {
            printf("Error");
        } else if (child == 0) {
            //Sets child pid
            childList[i] = getpid();
        }

        //Waits if the parent
        if(child != 0){
            wait(NULL);
        }
        else{
            //Assigns child respective command from list
            for(i = 0; i < maxCom; i++)
            {
                if(childList[i] == getpid())
                {
                    //Executes command
                    system(commandList[i]);
                }
            }
        }
    }

    return(0);
}
