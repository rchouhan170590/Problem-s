#include <bits/stdc++.h> 
using namespace std; 
void print_permutation(int * arr, int n, int r);
int main() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=1;i<=n;i++)
	 arr[i-1]=i;       //storing number from 1 to n;
	print_permutation(arr, n-1,0); // print the permutation of numbers;
	return 0; 
}

void print_permutation(int * arr, int n, int r) 
{ 
	if (r == n)
	{                             // if r = n (base case ) then we print array 
	    for(int s=0;s<=n;s++)    
		   cout<<arr[s];
		cout<<endl;
	}
	else              // if r !=n than 
	{ 
	    //arr[] = { 1,2,3}  before array.
		for (int i = r; i <= n; i++) 
		{ 
			swap(arr[r], arr[i]);      // fix the number and then go for  remaining number. 
			//arr[] = {1,2,3}   one is fix and now look for 2 and 3. 
			print_permutation(arr, n, r+1);   
			// give arr = 1,2,3 and 1,3,2
			swap(arr[r], arr[i]);
			//arr = 1,2,3;
		} 
		
	} 
}
/*
// arr [1,2,3]
   arr = [2,1,3]   swap 1 and 2 . to 2 
   forget 2 
     new array [1,3];
        fix 1 
          next fix 3 
            print 
            
