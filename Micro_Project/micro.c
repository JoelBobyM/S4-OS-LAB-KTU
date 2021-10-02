#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
void main()
{
  pid_t pid;
  printf("ENTER THE PID OF PROCESS TO BE KILLED : ");
  scanf("%d",&pid);
  int a = kill(pid, SIGKILL);
  if(a==0)
    printf("PROCESS SUCESSFULLY KILLED\n");
  else
    printf("ERROR WHILE KILL OPERATION : %d\n",a);
}
