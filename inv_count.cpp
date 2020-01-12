//Counting the number of inversions in an array using recursion. Time complexity: O(n*logn)

#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator itr;
typedef vector<int> vec;

int split_inv(itr a, itr end) //counting the number of split inversions
{
    int n = end-a;
    sort(a, a+n/2);
    sort(a+n/2, end); 
    itr i = a, j = a+n/2;
    int count = 0;
    
    for(; (i != a+n/2 && j != end);)
    {
        if(*i <= *j)
            i++;
        else
        {
            j++;
            count += (a+n/2)-i;
        }        
    }

    return count;
}

int count_inv(itr a, itr end)
{
    int n = end-a;
    if(n == 1)
        return 0;

    int b = count_inv(a, a+n/2);
    int c = count_inv(a+n/2, end);

    return b+c+split_inv(a, end);
}

int main()
{
    int n, temp;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {    
        cin >> temp;
        a.push_back(temp);
    }

    int res = count_inv(a.begin(), a.end());
    cout << res << endl;
    return 0;
}