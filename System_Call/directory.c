#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
void main()
{
  DIR *d;
  struct dirent *de;
  d=opendir(".");
  while(de=readdir(d))
  {
    if(de->d_type == DT_DIR )
    {
      printf("%s\n",de->d_name);
    }
  }
}

