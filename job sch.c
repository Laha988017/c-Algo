#include<stdio.h>
int n,i,j,k,t,a=0;
int check(int s[],int p)
  {
     int ptr=0,i;
     for(i=0;i<n;i++)
      {
       if(s[i]==p)
          ptr++;
      }
     if(ptr==0)
        return 1;
     else
        return 0;
  }

int main()
{
  printf("Enter the number of jobs: ");
  scanf("%d",&n);
  int slot[n],profit,p[n],d[n];
  for(i=0;i<n;i++)
    {
      printf("\n Enter the profit of job %d:",i+1);
      scanf("%d",&p[i]);
      printf("\n Enter the deadline of job %d:",i+1);
      scanf("%d",&d[i]);
    }
  for(i=0;i<n;i++)
   for(j=i+1;j<n;j++)
    if(p[i]<p[j])
     {
       t=p[i];
       p[i]=p[j];
       p[j]=t;
       t=d[i];
       d[i]=d[j];
       d[j]=t;
     }
   for(i=0;i<n;i++)
     slot[i]=0;
   for(i=0;i<n;i++)
    for(j=d[i];j>0;j--)
      {
       if(check(slot,j)==1)
        {
         slot[i]=j;
         break;
        }
      }
    printf("\n\n SL.NO.   PROFIT  DEADLINE  SLOT ALLOTTED ");
    for(i=0;i<n;i++)
     {
      if(slot[i]>0)
       {
        printf("\n\n   %d       %d        %d        [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
        a+=p[i];
      }
      else
       printf("\n\n   %d       %d        %d       REJECTED", i+1,p[i],d[i]);
     }
   printf("\nTotal profit:%d\n\n",a);
}

