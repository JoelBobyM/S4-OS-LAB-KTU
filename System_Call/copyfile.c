#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
void main(int argc, char *argv[])
{
  if(argc != 3)
  {
  printf("Argument Error.\n");
  return;
  }
  char *file1= argv[1];
  char *file2= argv[2];
  char rbuf[100];
  int fd1,fd2;
  fd1=open(file1,O_RDONLY);
  fd2=open(file2,O_CREAT|O_WRONLY,S_IRWXU);
  char wbuf[100]="Start\n";
  write(fd2,wbuf,strlen(wbuf));
  read(fd1,rbuf,100);
  write(fd2,rbuf,strlen(rbuf));
  char wbuf1[100]="Stop";
  write(fd2,wbuf1,strlen(wbuf1));
  printf("Successfully copied\n");
  close(fd1);
  close(fd2);
}
