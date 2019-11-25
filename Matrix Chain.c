#include<stdio.h>
#include<limits.h>
int s[10][10];
void print(int i, int j)
{
if(i==j)
	printf("A%d",i);
else
	{
	printf("(");
	print(i,s[i][j]);
	print(s[i][j]+1,j);
	printf(")");
	}
}
int MatrixChain(int p[],int n)
{
int cost[n][n];
 int i, j, k, L, q;

    for (i=1; i<n; i++)
        cost[i][i] = 0;
for (L=2; L<n; L++) //chain length
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            cost[i][j] = INT_MAX;
		for (k=i; k<=j-1; k++)
 		{
  		 q = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
  		 if (q < cost[i][j])
  		 {
   		 cost[i][j] = q;
   		 s[i][j]= k;
   		}
		}
	}
} 

printf("\n\n");
printf("\n\n");
return cost[1][n-1];
}
int main()
{
int n,i;
printf("\nEnter the no. of matrices:");
scanf("%d",&n);
n++;
int arr[n];
printf("\nEnter the dimensions of matrices:\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Minimum no. of multiplications is:%d\n",MatrixChain(arr,n));
printf("Matrix parenthesis :");
print(1,n-1);
return 0;
}

