#include<stdio.h>
void main()
{
	int n,rs[25],f,m[10],next=1,count[30],pf=0,i,j,k,min,flag[30];
	printf("Enter the length of string:");
	scanf("%d",&n);
	printf("Enter the reference string:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	printf("Enter the no of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
		count[i]=0;
	}
	printf("Ref String\t   Page Frames\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",rs[i]);
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				for(k=0;k<f;k++)
					printf("%d\t",rs[k]);
				printf("\n");
				flag[i]=1;
				count[j]=next;
				next++;
			}
		}
		if(flag[i]==0)
		{
			if(i<f)
			{
				m[i]=rs[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(k=0;k<f;k++)
				{
					if(count[k]<count[min])
						min=k;
				}
				m[min]=rs[i];
				count[min]=next;
				next++;
			}
			pf++;
			for(j=0;j<f;j++)
			{	
			for(j=0;j<f;j++)
			{
				printf("%d\t",m[j]);
			}
			printf("\n");
			}
		}
	}
	printf("Page faults=%d\n",pf);
}
