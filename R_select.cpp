/*
    Algorithm for finding the k^th minimum element in the given array using randomized selection.
    Average time complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int kthMin(int* a, int size, int k)
{
    if(size == 1) return *a;

    int pivot = *a, i = 1;
    for(int j = 1; j < size; j++)
    {
        if(*(a+j) < pivot)
        {
            int temp = *(a+j);
            *(a+j) = *(a+i);
            *(a+i) = temp;
            i++;
        }
    }
    
    if(i == k) return pivot;

    else if((i > k) && (i > 1))
    {
        int res = kthMin(a+1, i-1, k);
        return res;
    }

    else if(size-i > 0)
    {
        int res = kthMin(a+i, size-i, k-i);
        return res;
    }
    return 0;    
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << kthMin(a, n, k) << endl;
    return 0;
}