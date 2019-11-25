#include<stdio.h>
int binarysearch(int [],int , int ,int );
int main()
{
int i,n,pos,a[10];
printf("enter the no of elements:\n");
scanf("%d", &n);
printf("enter the array:\n");
for(i=0;i<n;i++)
{
scanf("%d", &a[i]);
}
int search, low,high;
low=0;
high=n;
printf("enter the element to search:\n");
scanf("%d", &search);
pos=binarysearch(a,search,low,high);
printf("position %d\n",pos+1);
}
int binarysearch(int a[],int search,int low,int high)
{
int mid;
//if(high<low)
//{
//printf("not possible\n");
//}
mid=(low+high)/2;
if(a[mid]<search)
{
binarysearch(a,search,mid+1,high);
}
else if(a[mid]>search)
{
binarysearch(a,search,low,mid-1);
}
else
{
return mid;
}
}
