include<stdio.h>
#include<string.h>
struct process
{
  char name[20];
  int at,tt,bt,wt,ct,st;
}p[20],temp;
void main()
{
  int n,i,tmp,low,j;
  printf("ENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)                         //Input process details
  {
    printf("\nENTER DETAILS OF PROCESS %d",i+1);
    printf("\nPROCESS NAME : ");
    scanf(" %s",p[i].name);
    printf("ARRIVAL TIME : ");
    scanf("%d",&p[i].at);
    printf("BURST TIME : ");
    scanf("%d",&p[i].bt);
  }
  for(i=0;i<n;i++)                       //Sorting based on at
  {
    for(j=0;j<n-i-1;j++)
    {
      if(p[j].at > p[j+1].at)
      {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
  p[0].ct = p[0].at + p[0].bt;
  p[0].tt = p[0].ct - p[0].at;
  p[0].wt = p[0].tt - p[0].bt;
  for(i=1;i<n;i++)
  {
    tmp = p[i-1].ct;
    low = p[i].bt;
    for(j=i;j<n;j++)
    {
      if(tmp>=p[j].at && low>=p[j].bt)
      {
        low  = p[j].bt;
        val = j;
      }
    }
    p[val].ct = tmp + p[val].bt;
    p[val].tt = p[val].ct - p[val].at;
    p[val].wt = p[val].tt - p[val].bt;

    temp = p[val];
    p[val] = p[i];
    p[i] = temp;
  }
}
