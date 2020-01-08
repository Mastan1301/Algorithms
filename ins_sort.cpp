/* Insertion sort algorithm O(n^2)

In this algorithm, we compare the element with the next element, and if A[i] > A[i+1], they are swapped. 
We run it for multiple times till the array is sorted.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A[] = {5, 3, 9, 2, 6, 8};
	int n = sizeof(A)/sizeof(A[0]), hole = 0, value = 0;
	
	for(int i = 1; i < n; i++)
	{
		hole = i-1;
		value = A[hole+1];
		
		while((hole>=0)&&(A[hole] > value))
		{
			A[hole+1] = A[hole];
			hole--;
		}
		A[hole+1] = value;
	}
	
	for(int i = 0; i < n; i++)
			cout << A[i] << " ";
	return 0;
}


