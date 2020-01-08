/*Merge sort algorithm T(6nlogn + 6n)
	Note: Don't use sizeof() outside of main function in C/C++ */
#include <iostream>
#include <cstdio>
using namespace std;

int* merge(int* A, int* B, int s_a, int s_b)
{
	int* res = new int[s_a+s_b];
	int i = 0, j = 0, k;

	for(k = 0; (i < s_a && j < s_b); k++)
	{
		if(*(A+i) > *(B+j))
		{
			res[k] = *(B+j);
			j++;
		}
		else
		{
			res[k] = *(A+i);
			i++;
		}		
	}

	while(i < s_a)
	{
		res[k] = *(A+i);
		k++;
		i++;
	}

	while(j < s_b)
	{
		res[k] = *(B+j);
		k++;
		j++;
	}
	return res;
}

int* mergeSort(int* a, int* end)
{
	int n = end-a + 1;
	int mid;
	if(n == 1)
		return a;

	if(n%2 == 0) mid = (n/2);
	else mid = (n/2)+1;

	int* t1 = mergeSort(a, a+mid-1);
	int* t2 = mergeSort(a+mid, end);
	return merge(t1, t2, mid, n-mid);
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int* res = mergeSort(a, a+n-1);
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";

	cout << endl;
	return 0;
}