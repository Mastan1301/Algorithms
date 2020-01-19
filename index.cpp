/*
    You are given a sorted (from smallest to largest) array A of n distinct integers which can be positive, negative, 
    or zero. You want to decide whether or not there is an index i such that A[i] = i. Design the fastest algorithm 
    that you can for solving this problem.

    Time complexity: O(log n)
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vec::iterator itr;

bool check(itr start, itr end, int pos)
{
    int n = end-start;
    if(n == 1)
        return (*(start) == pos);

    if(*(start+(n/2)-1) >= (n/2)) //making use of the sorted property
    {
         bool t1 = check(start, start+(n/2), pos);
         return t1;
    }

    if(*(start+(n/2)-1) == (n/2)-1)
        return true;

    bool t2 = check(start+(n/2), end, pos + n/2);
    return t2;
}

int main()
{
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(check(a.begin(), a.end(), 0))
        cout << "True" << endl;    
    else
        cout << "False" << endl;
    
    return 0;
}