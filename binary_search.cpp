/* Binary Search algortihm for a sorted array.
    Time Complexity: O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

bool bin_search(vector<int> a, int val)
{
    
    int n = a.size();  

    if(n == 1) return (a[0] == val);

    bool res =  false;

    if(val == a[(n/2) - 1])
        return true;

    else if(val > a[(n/2) - 1])
    {
        vector<int> temp(a.begin()+n/2, a.end());
        res =  bin_search(temp, val);
    }

    else
    {
        vector<int> temp(a.begin(), a.begin()+n/2);
        res = bin_search(temp, val);
    }

    return res;    
}

int main(){
    int n, t, val;
    cin >> t; //no. of test cases

    while(t--)
    {
        cin >> n >> val;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        bool res = bin_search(a, val);
        if(res) cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}