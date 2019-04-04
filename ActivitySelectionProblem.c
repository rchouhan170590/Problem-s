// For Greedy algorithem following link.
// https://github.com/rchouhan170590/GreedyAlgorithms/blob/master/ActivitySelectionProblem.c

#include<stdio.h>
int MaxActivity(int S[],int F[],int ,int,int);
int main()
{
   int size;
   scanf("%d",&size);
   int S[size],F[size];

   for(int k=0;k<size;k++)
     scanf("%d",&S[k]);
   for(int k=0;k<size;k++)
      scanf("%d",&F[k]);

   int a=MaxActivity(S,F,size,-1,0);
   printf("%d",a);
   return 0;
}

int MaxActivity(int S[],int F[],int size,int end,int i)
{
   if(i>=size)
     return 0;
   int b=0;
   int a=MaxActivity(S,F,size,end,i+1);
   if(end<=S[i])
   {
     b =1+MaxActivity(S,F,size,F[i],i+1);
   }
   int c=(a>b?a:b);
   return c;
}
