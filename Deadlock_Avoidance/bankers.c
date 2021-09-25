#include<stdio.h>
#include<string.h>

int avail[100];
int resmax[100];
int maxalloc[100];
struct process
{
  char name[100];
  int max[100];
  int alloc[100];
  int need[100];
  int done;
}p[20],temp;
void main()
{
  int i,j,r,pr,flag,ls,ml=0;
  char str[100] = "";
  printf("ENTER THE NUMBER OF RESOURCES : ");
  scanf("%d",&r);
  printf("MAXIMUM RESOURCE COUNT FOR :- \n");
  for(j=0;j<r;j++)
  {
    printf("\tRESOURCE %d : ",j+1);
    scanf("%d",&resmax[j]);
  }
  printf("\nENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&pr);
  for(i=0;i<pr;i++)
  {
    printf("\nENTER PROCESS NAME : ");
    scanf(" %s",p[i].name);
    printf("\nDETAILS FOR PROCESS %s",p[i].name);
    for(j=0;j<r;j++)
    {
      printf("\n\tMAXIMUM ALLOCATION FOR RESOURCE %d : ",j+1);
      scanf("%d",&p[i].max[j]);

      printf("\tALLOCATED RESOURCE FOR RESOURCE %d : ",j+1);
      scanf("%d",&p[i].alloc[j]);
      maxalloc[j] = maxalloc[j] + p[i].alloc[j];

    }
    for(j=0;j<r;j++)
    {
      p[i].need[j] = p[i].max[j] - p[i].alloc[j];
    }
    p[i].done = 0;
  }

  printf("\n  PROCESS \tMAXIMUM \tALLOCATED \tREMAINING\n");
  for(i=0;i<pr;i++)
  {
    printf("\n     %s      \t ",p[i].name);
    for(j=0;j<r;j++)    //Max
    {
      printf("%d ",p[i].max[j]);
    }
    printf(" \t  ");
    for(j=0;j<r;j++)    //Alloc
    {
      printf("%d ",p[i].alloc[j]);
    }
    printf("\t  ");
    for(j=0;j<r;j++)    //Need
    {
      printf("%d ",p[i].need[j]);
    }
  }
  for (i=0;i<r;i++)
  {
    avail[i] = resmax[i] - maxalloc[i];
  }
  printf("\n\nORDER OF EXECUTION :- \n");
  for(i=0,ls=0;ml<r;)
  {
    for(flag = 0,j=0;j<r;j++)
    {
      if(avail[j]>=p[i].need[j])
      {
        flag++;
      }
    }
    if(flag == r && p[i].done == 0)
    {
      p[i].done = ls+1;
      for(ml=0,j=0;j<r;j++)
      {
        avail[j] = avail[j] + p[i].alloc[j];
        if(avail[j]==resmax[j])
        {
          ml++;
        }
      }
      ls++;
      printf("\t\t%s IS VISTED \n",p[i].name);
      strcat(str,p[i].name);
      strcat(str,", ");
    }
    else
    {
      i++;
      if(i==pr)
      {
        i=0;
      }
    }
  }
  if(ml==r && ls == pr)
  {
    printf("\nSYSTEM IS IN SAFE STATE\n");
    printf("\nSAFE STATE SEQUENCE : %s",str);
    printf("\b\b.  \n");
  }
  else
  {
    printf("\nSYSTEM IS IN UNSAFE STATE\n");
  }
}
