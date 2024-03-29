#include <stdio.h>
#include<stdlib.h>

int merge_Sort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
    int* temp = (int*)malloc(sizeof(int) * array_size);
    return merge_Sort(arr, temp, 0, array_size - 1);
}

int merge_Sort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
{
        mid = (right + left) / 2;
        inv_count = merge_Sort(arr, temp, left, mid);
        inv_count += merge_Sort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
}
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left,j = mid,k = left;
    while ((i <= mid - 1) && (j <= right))
{
        if (arr[i] <= arr[j])
{
           temp[k++] = arr[i++];
}
        else
{
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
}
}
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int main(int argv, char** args)
{
int i,n,arr[100];
 printf("Enter the number of elements in the array :");
scanf("%d",&n);
printf("Enter the elements :  ");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf(" Number of inversions are %d \n", mergeSort(arr, n));
printf("sorted array : ");
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
    return 0;

}
