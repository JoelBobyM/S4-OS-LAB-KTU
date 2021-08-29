#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
void main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("INVALID NUMBER OF ARGUMENTS.\n");
    exit(0);
  }
  char *file1 = argv[1];
  char *file2 = argv[2];
  char wbuf[100] = "START\n";
  char rbuf[100];
  int fd1 = open(file1,O_RDONLY);
  int fd2 = open(file2,O_CREAT|O_WRONLY,S_IRWXU);
  write(fd2,wbuf,strlen(wbuf));
  read(fd1,rbuf,100);
  write(fd2,rbuf,strlen(rbuf));
  strcpy(wbuf,"STOP");
  write(fd2,wbuf,strlen(wbuf));
  printf("SUCCESSFULLY COPIED\n");
  close(fd1);
  close(fd2);
}
