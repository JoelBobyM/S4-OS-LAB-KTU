#include <stdio.h>
#include <stdlib.h>
int pno,fno,i,j,pg[100],fr[100];
void input()
{
  printf("ENTER THE NUMBER OF PAGES : ");
	scanf("%d",&pno); 
	for(i=0;i<pno;i++)
	{
		printf("ENTER THE PAGE NUMBER %d: ",i+1);
		scanf("%d",&pg[i]);
	}
	printf("ENTER THE NUMBER OF FRAMES : ");
	scanf("%d",&fno);
	for(i=0;i<fno;i++)
	{
		fr[i]=-1;
	}
}
void lru()
{
  int fnd,k,top,stack[100],m;
  printf("\n\tREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");
  for(m=0,k=0,i=0,top=-1;i<pno;i++)
  {
    for(fnd=0,j=0;j<fno;j++)
    {
      if(pg[i] == fr[j])
      {
        fnd = 1;
        k=j;
      }
    }
    if(fnd == 1)
    {
      for(;k<fno-1;k++)
      {
        stack[k] = stack[k+1];
      }
      stack[k] = pg[i];
    }
    else
    {
      if(m<fno)
      {
        top++;
        stack[top] = pg[i];
        fr[m] = pg[i];
        m++;
      }
      else
      {
        for(j=0;j<fno;j++)
        {
          if(stack[0] == fr[j])
          {
            k=j;
          }
        }
        fr[k] = pg[i];
        for(k=0;k<fno-1;k++)
        {
          stack[k] = stack[k+1];
          
        }
        stack[k] = pg[i];
      }
    }
    
    printf("\t\t%d\t\t  ",pg[i]);
    for(j=0;j<fno;j++)
    {
      if(fr[j] != -1)
			{
				printf("%d   ",fr[j]);
			}
    }
    if(fnd==1)
		{
			printf("\t\t    HIT\n");
		}
		else
		{
			printf("\t\t    MISS\n");
		}
	}
}
void main()
{
	input();
	lru();
}
