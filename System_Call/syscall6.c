#include<stdio.h>
#include<unistd.h>
void main()
{
  fork();
  fork();
  fork();
  fork();
  printf("Hello World\n");
}
  
