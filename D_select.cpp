/*
    Deterministic Selection Algorithm: Algorithm for finding the k^th minimum (k^th order statistic) 
    in a given array by selecting the median of medians as the pivot.
    
    Time complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

static int t = 0;

int* median(int a[], int size)
{
    t = (size/5)+1;
    if(size%5 == 0) t--;
    int* C = new int[t];
    for(int i = 0, j = 0; i < size; i += 5, j++)
    {
        if(i+5 <= size)
        {
            sort(a+i, a+i+5);
            C[j] = a[i+2];
            //cout << C[j] << " ";
        }
        else
        {
            sort(a+i, a+size);
            int temp = ((size-i)/2) - (1 - ((size-i)%2)); //middle element
            C[j] = a[i+temp];
            //cout << C[j] << " ";
        }
    } 

    return C;    
}

int DSelect(int *a, int size, int stat)
{
    if(size == 1) return *a;

    int *C = median(a, size);
    int p = DSelect(C, t, (t/2)+(t%2)); //assigning median of medians as the pivot
    int pivot;
    for(int i = 0; i < size; i++) //linear search for the obtained median
    {
        if(a[i] == p)
        {
            pivot = i;
            break;
        }
    }
    int i = 1;
    a[pivot] = a[0];
    a[0] = p;

    for(int j = 1; j < size; j++)
    {
        if(a[j] < p)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }

    if(stat == i) return p;

    else if(stat < i)
    {
        int res = DSelect(a+1, i-1, stat);
        return res;
    } 
    else
    {
        int res = DSelect(a+i, size-i, stat-i);
        return res;
    }  

    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << DSelect(a, n, k) << endl;
    return 0;
}
