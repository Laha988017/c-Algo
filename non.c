#include<stdio.h>
int main()
{
int n,low,high,mid,i,search,flag=0,a[10];
printf("enter the no of elements\n");
scanf("%d", &n);
printf("enter the array\n");
for(i=0;i<n;i++)
{
scanf("%d", &a[i]);
}
low=0;
high=n;
printf("enter the searching element\n");
scanf("%d", &search);
while(flag==0)
{
mid=(low+high)/2;
if(search<a[mid])
{
high=mid-1;
}
else if(search>a[mid])
{
low=mid+1;
}
else
{
flag=1;
printf("position %d\n", mid);
}
}
}
