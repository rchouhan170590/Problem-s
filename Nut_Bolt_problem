#include<stdio.h>
void Mapping(int,int,int [],int []);
int Map(int,int [],int ,int );
void swap(int * ,int *);
int main()
{
    int size;
    scanf("%d",&size);
    int Nut[size],Bolt[size];
    for(int i=0;i<size;i++)
      scanf("%d",&Nut[i]);

    for(int i=0;i<size;i++)
      scanf("%d",&Bolt[i]);
      
    Mapping(0,size-1,Nut,Bolt);
    printf("Nut : ");
    for(int i=0;i<size;i++)
      printf("%d ",Nut[i]);
    printf("\nBolt : ");
    for(int i=0;i<size;i++)
      printf("%d ",Bolt[i]);   
    return 0;
}
void Mapping(int s,int e,int Nut[],int Bolt[])
{
    if(s>=e)
      return ;
    int index=Map(Nut[e],Bolt,s,e);
    index=Map(Bolt[index],Nut,s,e);
    Mapping(s,index-1,Nut,Bolt);
    Mapping(index+1,e,Nut,Bolt);
}
int Map(int key,int Arr[],int s,int e)
{
    int index=s;
    for(int i=s;i<e;i++)
    {
        if(Arr[i]<key)
        {
            swap(&Arr[i],&Arr[index]);
            index++;
        }
        else if(Arr[i]==key)
        {
            swap(&Arr[i],&Arr[e]);
            i--;
        }
    }
    swap(&Arr[e],&Arr[index]);
    return index;
}
void swap(int * a,int * b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
