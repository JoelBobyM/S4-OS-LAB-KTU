#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
void main()
{
  struct stat buf;
  stat("./hello.c",&buf);
  printf("%d\n",buf.st_mode);
}

