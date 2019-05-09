#include <stdio.h>
#include <unistd.h>

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
        //printf("%s", line);
        //Saves line to command list
        int i = 0;
        for(i; i < 256; i++)
        {
            commandList[maxCom][i] = line[i];
        }
        maxCom++;
    }

    pid_t parent = getpid();
    pid_t child = 0;
    pid_t childList[maxCom];
    int i = 0;
    for(i; i < maxCom; i++) {
        child = fork();
        if(child < 0) {
            printf("Error");
            //break;
        } else if (child == 0) {
            //printf("Child (%d): %d\n", i + 1, getpid());
            childList[i] = getpid();
            //break;
        }

        if(child != 0){
            wait(NULL);
        }
        else{
            for(i = 0; i < maxCom; i++)
            {
                if(childList[i] == getpid())
                {
                    //printf("%s", commandList[i]);
                    system(commandList[i]);
                }
            }
        }
    }



    return(0);
}
