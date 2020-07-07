#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>
#include<unistd.h>

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

      if(pid[i]<0)
      {
        printf("ERROR\n");
      }

       if(pid[i]==0)
      {
         	 sigset_t sigs;
        	int sig_recvd = 0;
        	sigset_t old_mask;
	        sigemptyset(&sigs);
	        sigaddset(&sigs, SIGUSR1);
	        sigprocmask(SIG_BLOCK, &sigs, NULL);
	        sigwait(&sigs, &sig_recvd);

	         execvp(line[i],args);

        }
       
     else
     { 
       sleep(3);
       kill(pid[i],SIGUSR1);

       sleep(3); 
       kill(pid[i],SIGSTOP);

       sleep(5);
       kill(pid[i],SIGCONT);

       sleep(5);
       kill(pid[i],SIGKILL);
       wait(NULL);
 
      }
    }
    printf("\n");
    return 0;
}
