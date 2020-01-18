/*
    You are a given a unimodal array of n distinct elements, meaning that its entries are in increasing order up until 
    its maximum element, after which its elements are in decreasing order. Give an algorithm to compute 
    the maximum element that runs in O(log n) time.
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vec::iterator itr;

int uniMax(itr start, itr end)
{
    int n = end - start;

    if(n == 1)
        return *start;

    if(n == 2)
        return max(*start, *(start+1));
    
    int res;
    if(*(start+(n/2)-1) > *(start+n/2))
    {
        if(*(start+(n/2)-1) > *(start+n/2-2))
            return *(start+(n/2)-1);

        res = uniMax(start, start+n/2);
    }

    else if(*(start+(n/2)-1) < *(start+n/2))
    {
        res = uniMax(start+n/2, end);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << uniMax(a.begin(), a.end()) << endl;
    return 0;   
}