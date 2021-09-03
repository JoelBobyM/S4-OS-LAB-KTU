include<stdio.h>
#include<string.h>
struct process
{
  char name[20];
  int at,tt,bt,wt,ct,status;
}p[20],temp;
struct done
{
  char name[20];
  int st,ct;
}d[20];
void main()
{
  int n,i;
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
    p[i].status = 0;
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
}
