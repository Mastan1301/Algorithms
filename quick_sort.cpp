/* 
    Quick Sort algorithm.
    Average time complexity: O(nlog(n))
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vec::iterator itr;

vec quickSort(vec a)
{
    int size = a.size();
    if(size == 1)
    {
        return a;
    }

    int c = 1;
    int pivot = a[c-1], temp, i = c;  

    for(int j = c; j < size; j++)
    {
        if(a[j] < pivot)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
            }
    }

    if(i > 1)
   {
    vec l(a.begin()+1, a.begin()+i);
    vec left = quickSort(l);

    for(int j = c-1; j < i-1; j++)
    {
        a[j] = left[j];
    }
   }

    if(i <= size-1) 
    {
        vec r(a.begin()+i, a.begin()+size);
        vec right = quickSort(r);        
        for(int j = i; j < size; j++)
            a[j] = right[j-i];
    }

    a[i-1] = pivot;
    return a;
}

int main()
{
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vec res = quickSort(a);
    for(int i=  0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}