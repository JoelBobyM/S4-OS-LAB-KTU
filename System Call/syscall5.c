#include<stdio.h>
#include<unistd.h>
void main()
{
  pid_t p;
  p=fork();
  if(p==0)
  {
    printf("In child process:\n");
    printf("PID of parent process:%d",getppid());
    printf("\nPID of process:%d",getpid());
  }
  else if(p>0)
  {
    printf("In parent process:\n");
    printf("PID of parent process:%d",getppid());
    printf("\nPID of process:%d",getpid());
  }
  printf("\n");
}
