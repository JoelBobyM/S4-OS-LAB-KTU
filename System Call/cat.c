#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(int argc, char *argv[])
{
  if(argc != 2)
  {
  printf("Argument Error.\n");
  return;
  }
  char *file= argv[1];
  pid_t p=fork();
  int status;
  if(p==0)
  {
    execl("/usr/bin/cat","cat",file,NULL);
  }
  else
  {
    wait(&status);
  }
}

