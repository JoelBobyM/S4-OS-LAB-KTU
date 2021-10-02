#include<stdio.h>
#include<string.h>
void main()
{
	int tr[20],cr,n,i,sum=0,new;
	printf("ENTER THE NUMBER OF TRACKS : ");
	scanf("%d",&n);
	printf("ENTER THE HEAD POINTER POSITION : ");
	scanf("%d",&cr);
	printf("ENTER THE TRACKS TO BE TRAVERSED : ");
	for(i=0;i<n;i++)
	{
		new = 0;
		scanf("%d",&tr[i]);
		new=cr-tr[i];
		if(new<0)
		{
			new=tr[i]-cr;
		}
		cr=tr[i];
		sum=sum + new;
	}
	printf("TRAVERSED ORDER : ");
	for(i=0;i<n;i++)
		printf("%d => ",tr[i]);
 	printf("\b\b\b.   \nTOTAL HEAD MOVEMENTS : %d\n",sum);
}
