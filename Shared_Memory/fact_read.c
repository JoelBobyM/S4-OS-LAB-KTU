#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
void main()
{
  int fd = shm_open("/os_lab",O_CREAT|O_RDWR,0666);
  int ft = ftruncate(fd,sizeof(int));
  if (ft==-1)
  {
    printf("ERROR!!!\n");
  }
  else
  {
    printf("SHARED MEMORY CREATED\n");
    int *data = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    printf("ENTER THE NUMBER : ");
    scanf("%d",&data[0]);
    munmap(data,sizeof(int));
  }
  close(fd);
}
