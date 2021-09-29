#include<stdio.h>
int n,m,i,j,h,p,temp,k,total=0;
int t[100],a[100],diff[100];
void main()
{
  printf("ENTER THE NUMBER OF TRACKS : ");
  scanf("%d",&n);
  printf("ENTER THE HEAD POINTER POSITION : ");
  scanf("%d",&h);
  printf("ENTER THE TRACKS TO BE TRAVERSED : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&t[i]);
  }
  t[n+2] = 199;
  t[n+1] = 0;
  t[n] = h;
  n=n+3;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(t[j]>t[j+1])
      {
        temp=t[j];
        t[j]=t[j+1];
        t[j+1]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(t[i]==h)
    {
      k=i;
      break;
    }
  }
  if(h<(199-h))
  {
    for(i=k;i>=0;i--,p++)
    {
      a[p]=t[i];
    }
    for(i=n-1;i>k;i--,p++)
    {
      a[p]=t[i];
    }
  }
  else
  {
    for(i=k;i<n;i++,p++)
    {
      a[p]=t[i];
    }
    for(i=0;i<k;i++,p++)
    {
      a[p]=t[i];
    }
  }
  printf("TRAVERSED ORDER : ");
  for(i=0;i<p;i++)
  {
    printf("%d => ",a[i]);
  }
  for(total=0,j=0;j<p-1;j++)
  {
    int diff=0;
    if(a[j]>a[j+1])
    {
      diff=a[j]-a[j+1];
    }
    else
    {
      diff=a[j+1]-a[j];
    }
    total=total+diff;
  }
  printf("\b\b\b.  \nTOTAL HEAD MOVEMENTS : %d\n",total);
}
