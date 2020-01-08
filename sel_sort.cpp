/* selection sort algorithm O(n^2)
In this algo, we traverse from A[i] to A[n], find the min. element and swap it with A[i], for all i = 0:n-1.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A[] = {5, 3, 9, 2, 6};
	int n = sizeof(A)/sizeof(A[0]);
	int* temp = NULL;
	int t1 = 0;
	
	for(int i = 0; i < n; i++)
	{
		temp = min_element(A+i, A+n);
		int j = i;
		
		while(A[j] != *temp)
			j++;
			
		t1 = A[j];
		A[j] = A[i];
		A[i] = t1;
		
	}
	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	
	return 0;
}
