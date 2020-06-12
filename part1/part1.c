#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128 
#define RSIZ 10 

int main() 
{
    char line[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);	

    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n Launching Processes : \n");  
   char *args[]={NULL};  
  int pid[tot];

    for(i = 0; i < tot; ++i)
    {
        pid[i]=fork();
    if(pid[i]==0)
             {
                execvp(line[i],args);
             }
       }
    printf("\n");
    return 0;
}
