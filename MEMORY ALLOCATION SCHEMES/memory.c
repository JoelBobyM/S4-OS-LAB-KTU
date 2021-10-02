#include<stdio.h>
void firstfit(int p_size[],int n,int m_size[],int m)
{
  printf("\t\tFIRST FIT \n");
  int i,j,flag,psize[100],msize[100];
  for(i=0;i<n;i++)
  {
    psize[i] = p_size[i];
  }
  for(i=0;i<m;i++)
  {
    msize[i] = m_size[i];
  }
  for(i=0;i<n;i++)
  {
    flag=0;
    for(j=0;j<m;j++)
    {
      if(msize[j]>=psize[i])
      {
        printf("%d ALLOCATED IN %d MEMORY BLOCK",psize[i],msize[j]);
        msize[j] = msize[j]-psize[i];
        printf(" => %d SPACE REMAINING \n",msize[j]);
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      printf("%d CANNOT BE ALLOCATED \n",psize[i]);
    }
  }
}
void worstfit(int p_size[],int n,int m_size[],int m)
{
  printf("\t\tWORST FIT \n");
  int i,j,max,loc,psize[100],msize[100];
  for(i=0;i<n;i++)
  {
    psize[i] = p_size[i];
  }
  for(i=0;i<m;i++)
  {
    msize[i] = m_size[i];
  }
  for(i=0;i<n;i++)
  {
    max = msize[0];
    loc = 0;
    for(j=0;j<m;j++)
    {
      if(msize[j]>max)
      {
        max = msize[j];
        loc = j;
      }
    }
    if(max>=psize[i])
    {
      printf("%d ALLOCATED IN %d MEMORY BLOCK",psize[i],msize[loc]);
      msize[loc] = msize[loc]-psize[i];
      printf(" => %d SPACE REMAINING \n",msize[loc]);
    }
    else
    {
      printf("%d CANNOT BE ALLOCATED \n",psize[i]);
    }
  }
}
void bestfit(int p_size[],int n,int m_size[],int m)
{
  printf("\t\tBEST FIT \n");
  int i,j,max,loc,psize[100],msize[100];
  for(i=0;i<n;i++)
  {
    psize[i] = p_size[i];
  }
  for(i=0;i<m;i++)
  {
    msize[i] = m_size[i];
  }
  for(i=0;i<n;i++)
  {
    loc = -1;
    for(j=0;j<m;j++)
    {
      if(msize[j]>=psize[i])
      {
        if(loc == -1)
        {
          loc = j;
        }
        else if(msize[loc]>msize[j])
        {
          loc = j;
        }
      }
    }
    if(loc != -1)
    {
      printf("%d ALLOCATED IN %d MEMORY BLOCK",psize[i],msize[loc]);
      msize[loc] = msize[loc]-psize[i];
      printf(" => %d SPACE REMAINING \n",msize[loc]);
    }
    else
    {
      printf("%d CANNOT BE ALLOCATED \n",psize[i]);
    }
  }
}
void main()
{
  int i,p_size[100],m_size[100],n,m;
  printf("ENTER THE NUMBER OF PROCESS : ");
  scanf("%d",&n);
  printf("ENTER THE ARRAY OF PROCESS : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p_size[i]);
  }
  printf("ENTER THE NUMBER OF MEMORY BLOCK : ");
  scanf("%d",&m);
  printf("ENTER THE ARRAY OF MEMORY BLOCK : ");
  for(i=0;i<m;i++)
  {
    scanf("%d",&m_size[i]);
  }
  firstfit(p_size,n,m_size,m);
  bestfit(p_size,n,m_size,m);
  worstfit(p_size,n,m_size,m);
}
