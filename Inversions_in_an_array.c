#include<stdio.h>
#include<stdlib.h>
int mergeSort(int arr[], int array_size);  
int mergeDivde(int arr[], int temp[], int left, int right); //divide the problem into two small problem .
int mergeTwoPart(int arr[], int temp[], int left,int mid, int right); //merge the two divide array.
int main()  
{  
    int t;  //number of test case.
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        int n;
        scanf("%d",&n); // size of the array.
        int arr[n];
        for(int i=0;i<n;i++)
        {
           scanf("%d",&arr[i]);
        }
           printf("%d\n",mergeSort(arr,n));
    }
    return 0;  
}

int mergeSort(int arr[], int size)  
{  
    int* temp = (int*)malloc(sizeof(int) * size);  
    return mergeDivde(arr, temp, 0, size - 1);  
}

int mergeDivde(int arr[], int temp[], int left, int right)  
{  
    int mid, count = 0;  
    if (right > left)  
    {  
        mid = (right + left) / 2;  
        count = mergeDivde(arr, temp, left, mid) + mergeDivde(arr, temp, mid + 1, right);
        count += mergeTwoPart(arr, temp, left, mid + 1, right);  
    }  
    return count;  
}

int mergeTwoPart(int arr[], int temp[], int left,int mid, int right)  
{  
    int i, j, k;  
    int count = 0;  
  
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right))  
    {  
        if (arr[i] <= arr[j]) 
        {  
            temp[k++] = arr[i++];  
        }  
        else 
        {  
            temp[k++] = arr[j++];  
            count = count + (mid - i);  
        }  
    }  
    while (i <= mid - 1)  
        temp[k++] = arr[i++];  
    while (j <= right)  
        temp[k++] = arr[j++];  
    for (i = left; i <= right; i++)  
        arr[i] = temp[i];  
    return count;  
}
