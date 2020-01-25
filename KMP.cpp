/*
    Pattern search using KMP algorithm.
    Time complexity: O(n+m)
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator itr;
typedef vector<int> vec;

vec computeLPS(string p, int m)
{
    vec lps(m);
    lps[0] = 0;
    int l = 0;

    for(int i = 1; i < m; )
    {
        if(p[i] == p[l])
        {
            l++;
            lps[i] = l;
            i++;
        }

        else
        {
            if(l != 0)
            {
                l = lps[l-1];
            }

            else
            {
                lps[i] = 0;
                i++;
            }            
        }        
    }
    return lps;
}

int main()
{
    int t;
    string s, p;
    cin >> t;

    while(t--)
    {
        cin >> s >> p;
        vec lps = computeLPS(p, p.length());
        vec ind;
        int freq = 0, n = s.length(), m = p.length();
        
        for(int i = 0, j = 0; i < n; )
        {
            if(s[i] == p[j])
            {
                i++;
                j++;
            }

            if(j == m)
            {
                freq++;
                ind.push_back(i-j+1);
                j = lps[j-1];
            }

            else if(i < n && s[i] != p[j])
            {
                if(j != 0)
                    j = lps[j-1];

                else //j = 0
                    i++;
            }           
        }

        if(freq == 0)
            cout << "Not Found\n";

        else
        {
            cout << freq << endl;
            for(int i = 0; i < ind.size(); i++)
                cout << ind[i] << " ";

            cout << "\n\n";
        } 
       // cout << t << endl;         
    }

    return 0;
}