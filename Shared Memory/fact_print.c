#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
void main()
{
  int i,fact;
  int fd = shm_open("/os_lab",O_RDONLY,0666);
  int *data = (int *)mmap(NULL,sizeof(int),PROT_READ,MAP_SHARED,fd,0);
  int a = data[0];
  for(i=1,fact=1;i<=a;fact*=i,i++);
  printf("FACTORIAL OF %d IS : %d\n",a,fact);
  munmap(data,sizeof(int));
  close(fd);
  shm_unlink("/os_lab");
}
