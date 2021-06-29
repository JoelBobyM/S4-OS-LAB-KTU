#include<stdio.h>
#include<unistd.h>
void main()
{
  pid_t p;
  int i;
  p=fork();
  if(p==0)
  {
    printf("In child process:\n");
    for(i=1;i<=10;i++)
    {
      printf("%d ",i);
    }
    printf("\n");
  }
  else if(p>0)
  {
    printf("In parent process:\n");
    for(i=1;i<=10;i++)
    {
      printf("%d ",i);
    }
    printf("\n");
  }
}
