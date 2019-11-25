#include<stdio.h>
void knapsack(int n,float weight[10],float profit[10],float capacity)
{
float tp=0.0,wt=0.0,av=0.0;
int i;
for(i<0;i<n;i++)
{
if(wt<=capacity)
{
if((capacity-wt)<weight[i])
{
av=(capacity-wt)/weight[i];
wt=capacity;
tp=tp+(av*profit[i]);
break;
}
wt=wt+weight[i];
tp=tp+profit[i];
}
}
printf("\n Total Profit is %f: ",tp);
}
void main()
{
float weight[10],profit[10],p_ratio[10],temp,capacity;
int i,j,num;
printf("\n Enter the total no.of items: ");
scanf("%d",&num);
printf("\n Enter the Total Capacity : ");
scanf("%f",&capacity);
for(i=0;i<num;i++)
{
printf("Enter the  weight and profit of %d item :",i+1);
scanf("%f %f",&weight[i],&profit[i]);
}
for(i=0;i<num;i++)
{
p_ratio[i]=profit[i]/weight[i];
}

for(i=0;i<num;i++)
{
for(j=i+1;j<num;j++)
{
if(p_ratio[i]<p_ratio[j])
{
temp=p_ratio[j];
p_ratio[j]=p_ratio[i];
p_ratio[i]=temp;

temp=weight[j];
weight[j]=weight[i];
weight[i]=temp;

temp=profit[j];
profit[j]=profit[i];
profit[i]=temp;
}
}
}
printf("\n The sorted Profit Ratio, Weight, Profit are: ");
printf("\n P/L         W         P  ");
for(i=0;i<num;i++)
{
printf("\n %f %f %f",p_ratio[i],weight[i],profit[i]);
}
knapsack(num,weight,profit,capacity);
}
