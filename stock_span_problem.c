/*
The Stock Span Problem
problem statement - https://www.geeksforgeeks.org/the-stock-span-problem/
*/
#include<stdio.h>
void findSpan(int arr[],int n);
int main()
{
    int t;
    // t is the no. of test case 
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
    int n;
    // length of input array is n.
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    findSpan(arr,n);
    printf("\n");
    }
    return 0;
}

void findSpan(int arr[],int n)
{
    int stake[n];
    int span[n];
    span[0]=1;
    stake[0]=0;
    int top=0;
    for(int i=1;i<n;i++)
    {
        if(top==-1)
        {
          span[i]=i+1;
          stake[++top]=i;
        }
        else if(arr[i]>=arr[stake[top]])
        {
            top=top-1;
            i=i-1;
            //continue;
        }
        else
        {
            span[i]=i-stake[top];
            stake[++top]=i;
        }
    }
    
    for(int i=0;i<n;i++)
      printf("%d ",span[i]);
    return ;
}
