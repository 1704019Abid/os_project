#include<stdio.h>
#include<unistd.h>
int main()
{
int i=0;
printf("HI I AM SUM\n");

for(i=0;i<=1000;++i)
{ printf("SUM PID = %d & I am %d \n",getpid(),i);
  sleep(1);
}

}
