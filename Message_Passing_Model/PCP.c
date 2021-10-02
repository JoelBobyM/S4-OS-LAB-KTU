#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
sem_t mutex,full,empty;
int buffer[5],put=0,get=0,item=1,pro[20],con[20],gitem;
void *producer(void *arg)
{
  do
  {
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[put%5]=item;

    int *myid = (int *)arg;
    printf("PRODUCER %d PRODUCES %d ITEM => BUFFER[%d] : %d\n",*myid,buffer[put%5],put%5,item);
    item++;
    put++;
    sem_post(&mutex);
    sem_post(&full);
    sleep(3);
  }
  while(1);
}
void *consumer(void *arg)
{
  do
  {
    sem_wait(&full);
    sem_wait(&mutex);
    gitem=buffer[get%5];
    int *myid = (int *)arg;
    printf("CONSUMER %d CONSUMES %d ITEM OF BUFFER[%d]\n",*myid,gitem,get%5);
    get++;
    sem_post(&mutex);
    sem_post(&empty);
    sleep(2);
  }
  while(1);
}
void main()
{
  int p,c,j,k;
  pthread_t a[10],b[10];
  sem_init(&mutex,0,1);
  sem_init(&full,0,0);
  sem_init(&empty,0,5);
  printf("ENTER THE NUMBER OF PRODUCERS : ");
  scanf("%d",&p);
  printf("ENTER THE NUMBER OF CONSUMERS : ");
  scanf("%d",&c);
  for(j=0;j<p;j++)
  {
    pro[j]=j+1;
    pthread_create(&a[j],NULL,producer,(void *)&pro[j]);
  }
  for(k=0;k<c;k++)
  {
    con[k]=k+1;
    pthread_create(&b[k],NULL,consumer,(void *)&con[k]);
  }
  for(j=0;j<p;j++)
  {
    pthread_join(&a[j],NULL);
  }
  for(k=0;k<c;k++)
  {
    pthread_join(&b[k],NULL);
  }
}
