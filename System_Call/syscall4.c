#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
void main()
{
  DIR *d;
  d=opendir("fisat");
  if(d==NULL)
  {
    printf("Directory doesnot exist\n");
  }
  else
  {
    printf("Directory exist\n");
  }
}
