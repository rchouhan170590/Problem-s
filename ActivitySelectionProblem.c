// For Greedy algorithem following link.
// https://github.com/rchouhan170590/GreedyAlgorithms/blob/master/ActivitySelectionProblem.c

#include<stdio.h>
int MaxActivity(int S[],int F[],int ,int,int,int hold[]);
int main()
{
   int size;
   scanf("%d",&size);
   int S[size],F[size];

   for(int k=0;k<size;k++)
     scanf("%d",&S[k]);
   for(int k=0;k<size;k++)
      scanf("%d",&F[k]);
   int hold[size];    //hold the index of selected activity.
   int a=MaxActivity(S,F,size,-1,0,hold);
   printf("Total Number of activtiy : %d\n",a);
   printf("index of selected activity : ");
   for(int i=0;i<a;i++)
      printf("%d ",hold[i]);
   return 0;
}

int MaxActivity(int S[],int F[],int size,int end,int i,int hold[])
{
   if(i>=size)
     return 0;
   int b=0;
   int a=MaxActivity(S,F,size,end,i+1,hold);
   if(end<=S[i])
   {
     b =1+MaxActivity(S,F,size,F[i],i+1,hold);
   }
   int c=(a>b?a:b);
   if(b>a)
      hold[c-1]=i;
   return c;
}
