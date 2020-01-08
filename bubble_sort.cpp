/* Bubble sort algorithm O(n^2)

In this algorithm, we compare the element with the next element, and if A[i] > A[i+1], they are swapped. 
We run it for multiple times till the array is sorted.
*/

#include <iostream>
using namespace std;

int main()
{
	int A[] = {2, 7, 4, 1, 5, 3};
	int n = sizeof(A)/sizeof(A[0]);
	int t1 = 0, t2 = n-1, count = 0;
	
	while(t2 > 0)
	{
		count = 0;	
		for(int i = 0; i < t2; i++)
		{
			if(A[i] > A[i+1])
			{
				t1 = A[i];
				A[i] = A[i+1];
				A[i+1] = t1;
				count++;
			}
		}
		if(count == 0)
			break;
			
		t2--;
	}
	
	for(int i = 0; i < n; i++)
			cout << A[i] << " ";
			
	return 0;
}

