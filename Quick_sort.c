#include <stdio.h>
/*
It take a array and its size as input and return the sorted array .
(sorted in non-decreasing order).
it select last element of array as pivot and then placed it at 
it's right position. 
*/
void Quick_Sort(int,int,int []);
void swap(int *,int*);
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Quick_Sort(0,n-1,arr);
    for(int i=0;i<n;i++)
      printf("%d ",arr[i]);
    return 0;
}

void Quick_Sort(int s,int e,int arr[])
{
    if(s>=e)
      return ;
    int key=e;
    int index=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<=arr[key])
        {
            swap(&arr[i],&arr[index]);
            index++;
        }
    }
    swap(&arr[e],&arr[index]);
    key=index;
    
    Quick_Sort(s,key-1,arr);
    Quick_Sort(key,e,arr);
}
void swap(int * a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
