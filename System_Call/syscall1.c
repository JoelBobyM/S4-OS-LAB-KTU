#include<stdio.h>
#include<unistd.h>
void main()
{
  pid_t p;
  p=fork();
  if(p==0)
  {
    printf("I am child\n");
  }
  else if(p>0)
  {
    printf("I am parent\n");
  }
}
