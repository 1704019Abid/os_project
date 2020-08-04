#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>
#include<sys/wait.h>
#include<unistd.h>

#define LSIZ 128 
#define RSIZ 10 
pid_t pid[2];

int i,g,p;
int f=1,k=0;
void sig_handler(int signum)
{
  printf("\nInside handler function \n");   
   if(f==1)
   {
     kill(pid[k],SIGSTOP);
     kill(pid[f],SIGCONT);
 
     f=0;
     k=1;
     alarm(5);
    }

    else if(k==1)
    {
     kill(pid[k],SIGSTOP);
     kill(pid[f],SIGCONT);
     k=0;
     f=1;
     alarm(5);
    }
}



int main(int argc, char *argv[]) 
{
=======

int f=1,k=0;
void sig_handler(int signum)
{
  printf("\nInside handler function \n");   
   if(f==1)
   {
     kill(pid[k],SIGSTOP);
     kill(pid[f],SIGCONT);
 
     f=0;
     k=1;
     alarm(5);
    }

    else if(k==1)
    {
     kill(pid[k],SIGSTOP);
     kill(pid[f],SIGCONT);
     k=0;
     f=1;
     alarm(5);
    }
}



int main(int argc, char *argv[]) 
{
>>>>>>> 1e56e1b28a920f2426abfe03160934f2fc207af8
	char line[RSIZ][LSIZ];
	char fname[20];
        FILE *fptr = NULL; 
        int i = 0;
        int tot = 0;
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);	
<<<<<<< HEAD

        fptr = fopen(fname, "r");
        while(fgets(line[i], LSIZ, fptr)) 
	 {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
         }
        tot = i-1;

	 printf("\nLaunching Processes : \n");  
         char *args[]={NULL};  
         pid[tot];
 
         for(i = 0; i < tot; i++)
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

=======

        fptr = fopen(fname, "r");
        while(fgets(line[i], LSIZ, fptr)) 
	 {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
         }
        tot = i-1;

	 printf("\nLaunching Processes : \n");  
         char *args[]={NULL};  
         pid[tot];
 
         for(i = 0; i < tot; i++)
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

>>>>>>> 1e56e1b28a920f2426abfe03160934f2fc207af8
	      execvp(line[i],args);
            }
       
           else
           { 
              sleep(2);
              kill(pid[i],SIGUSR1);
           }
         }

         for (i=0;i<tot;i++)
         {    
           kill(pid[i],SIGSTOP);
           sleep(5);
         }
         for (i=0;i<tot;i++)
         {    
           kill(pid[i],SIGCONT);
           sleep(3);
         }

         signal(SIGALRM,sig_handler);
         alarm(4);
     
         for(i=0;i<2;i++)
         {
           int returnStatus;    
           waitpid(pid[i], &returnStatus, 0);  // Parent process waits here for child to terminate.

             if (returnStatus == 0)  // Verify child process terminated without error.  
              {
                 printf("The child process terminated normally.\n");    
              }
         }

   printf("yo\n");
    return 0;
}
