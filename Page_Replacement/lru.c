#include<stdio.h>
struct frames
{
	int content,count;
}frame[100];
void main()
{
	int i,j,k,p,f,page[100],cnt=1,min,pf=0,id=0;
	printf("ENTER THE NUMBER OF PAGES : ");
	scanf("%d",&p);
	printf("ENTER THE REFERENCING STRING : ");
	for(i=0;i<p;i++)
	{
		scanf("%d",&page[i]);
	}
	printf("ENTER THE NUMBER OF FRAMES : ");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		frame[i].content = -1;
		frame[i].count = 0;
	}
	printf("\nREFERENCING PAGE\tSTATUS\t\tFRAME CONTENT\n\n");
	for(i=0;i<p;i++)
	{
		printf("\t%d\t\t",page[i]);
		for(j=0;j<f;j++)
		{
			if(frame[j].content == page[i])
			{
				printf("HIT\t\t");
				frame[j].count = cnt++;
				break;
			}
		}
		if(j==f)
		{
			printf("MISS\t\t");
			if(id<f)
			{
				frame[id].content = page[i];
				frame[id].count = cnt++;
				id++;
			}
			else
			{
				min=0;
				for(k=0;k<f;k++)
				{
					if(frame[k].count<frame[min].count)
						min = k;
				}
				frame[min].content = page[i];
				frame[min].count = cnt++;
			}
			pf++;
		}
		for(j=0;j<f;j++)
		{
			if(frame[j].content !=-1)
				printf("%d\t",frame[j].cnt);
		}
		printf("\n");
	}
	printf("\nPAGE FAULT : %d\n",pf);
}
