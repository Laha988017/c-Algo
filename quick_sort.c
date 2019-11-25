#include<stdio.h>
#include<time.h>
int n;
int partition(int a[],int L,int R)
{
 int i,r,x;
 i=L+1;
 r=R;
printf("\npivot element is %d\n", a[L]);
 while(1)
  {
   while(a[L]>a[i])
    i++;
   while(a[L]<a[r])
    r--;
   if(r>i)
  {
   x=a[i];
   a[i]=a[r];
   a[r]=x;
   i++;
   r--;
  }
  else
   {
    x=a[L];
    a[L]=a[r];
    a[r]=x;
    return r;
   }
  }
 }

void quicksort(int a[],int p,int q)
{
 int y,i;
 static int k=0;
 if(q>p)
 {
  printf("\nunsorted array in step %d:\n",k++);
  for(i=0;i<n;i++)
   printf("%d  ",a[i]);
  y=partition(a,p,q);
  quicksort(a,p,y-1);
  quicksort(a,y+1,q);
 //for(i=0;i<=q;i++)
   //printf("%d",a[i]);
 }
}
void main()
{
 int a[20],i,p,q;
 p=0;
 printf("how many numbers you want to enter? : ");
 scanf("%d",&n);
 q=n-1;
 printf("enter the numbers:\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
// clock_t begin=clock();
 quicksort(a,p,q);
// clock_t end=clock();
// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 printf("\nthe sorted array is:\n");
 for(i=0;i<n;i++)
  printf("%d\n",a[i]);
// printf("time spent:%lf ",time_spent);
}


