#include <stdio.h>
struct frame
{
  int content;
  int freq;
  int cnt;
}frames[100];
void main()
{
  int i,j,pg,fr,cnt,pf,min,page[100],id=0;
  printf("ENTER THE NUMBER OF PAGES : ");
  scanf("%d",&pg);
  printf("ENTER THE REFERENCING STRING : ");
  for(i=0;i<pg;i++)
  {
    scanf("%d",&page[i]);
  }
  printf("ENTER THE NUMBER OF FRAMES : ");
  scanf("%d",&fr);
  for(i=0;i<fr;i++)
  {
    frames[i].content = -1;
    frames[i].freq = 0;
    frames[i].cnt = 0;
  }
  printf("\nREFERENCING PAGE\tSTATUS\t\tFRAME CONTENT\n\n");
  for(pf=0,cnt=1,i=0;i<pg;i++)
  {
    printf("\t%d\t\t",page[i]);
    for(j=0;j<fr;j++)
    {
      if(frames[j].content == page[i])
      {
        printf("HIT\t\t");
        frames[j].freq++;
        break;
      }
    }
    if(j == fr)
    {
      printf("MISS\t\t");
      if(id< fr)
      {
        frames[id].content = page[i];
        frames[id].freq++;
        frames[id].cnt = cnt++;
        id++;
      }
      else
      {
        for(min=0,j=0;j<fr;j++)
        {
          if(frames[min].freq > frames[j].freq)
          {
            min = j;
          }
          else if(frames[min].freq == frames[j].freq && frames[min].cnt > frames[j].cnt)
          {
            min = j;
          }
        }
        frames[min].content = page[i];
        frames[min].freq = 1;
        frames[min].cnt = cnt++;
      }
      pf++;
    }
    for(j=0;j<fr;j++)
    {
      if(frames[j].content !=-1)
        printf("%d\t",frames[j].content);
    }
    printf("\n");
  }
  printf("\nTOTAL PAGE FAULT : %d\n",pf);
}


/*

OUTPUT

ENTER THE NUMBER OF PAGES : 15
ENTER THE REFERENCING STRING : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2
ENTER THE NUMBER OF FRAMES : 3

REFERENCING PAGE	STATUS		FRAME CONTENT

	    7		         MISS		     7
	    0		         MISS		     7	0
	    1	           MISS		     7	0  	1
	    2		         MISS		     2	0 	1
	    0		         HIT		     2	0  	1
	    3		         MISS		     2	0	  3
	    0		         HIT		     2	0	  3
	    4		         MISS		     4	0 	3
	    2		         MISS		     4	0 	2
	    3		         MISS		     3	0 	2
	    0		         HIT	       3	0	  2
	    3		         HIT		     3	0  	2
	    2		         HIT		     3	0  	2
	    1	         	 MISS		     3	0  	1
	    2		         MISS		     3	0 	2

TOTAL PAGE FAULT : 10

*/