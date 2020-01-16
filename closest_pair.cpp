/*
    Closest pair algorithm in 2-D using Divide and Conquer paradigm.
    Applicable only when n = 2^i, where i is a natural number.
    Time Complexity: O(n*log(n))
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> vec_v;
//typedef vector<pair<int, int>> vec_p;

float dist(vec_v);
bool sortcolx(const vector<int>&, const vector<int>&);
bool sortcoly(const vector<int>&, const vector<int>&);

vec_v closePair(vec_v a)
{
    int n = a.size();
    int mid = n/2;
    vec_v res(2, vec(2));
    if(n == 2)
    {
        res[0] = {a[0][0], a[0][1]};
        res[1] = {a[1][0], a[1][1]};
        return res;
    }

    sort(a.begin(), a.end(), sortcolx); //merge sort O(nlog(n))
    vec_v Q(a.begin(), a.begin()+mid); //dividing into left and right
    vec_v R(a.begin()+mid, a.end());

    float best = min(dist(closePair(Q)), dist(closePair(R)));  

    if(best == dist(closePair(Q))) res = closePair(Q);
    else res = closePair(R); 

    sort(a.begin(), a.end(), sortcoly);
    vec py, sy;
    for(int i = 0; i < n; i++)
    {
       py.push_back(a[i][1]);

       if((float)abs(a[i][0] - Q[mid-1][0]) <= best)   //making a copy of the x-coordinates of the points in the vertical strip sorted by y-coordinates.
            sy.push_back(a[i][0]);            
    }  

    int p, q;
    int k;
    n = sy.size();

    if(n > 7)
        for(int i = 0; i < n-7; i++)
        {
            for(int j = 1; j <= 7; j++)
            {
                p = i;
                q = i+j;
                vec_v temp{{sy[p], 0}, {sy[q], 0}};
                if(dist(temp) < best)
                {
                    best = dist(temp);
                    res[0] = {a[p][0], a[p][1]};
                    res[1] = {a[q][0], a[q][1]};
                }
            } 
        } 

    else
    {
       for(int j = 1; j < n; j++)
            {
                p = 0;
                q = j;
                vec_v temp{{sy[p], 0}, {sy[q], 0}};
                if(dist(temp) < best)
                {
                    best = dist(temp);
                    res[0] = {a[p][0], a[p][1]};
                    res[1] = {a[q][0], a[q][1]};
                }
            } 
    }    
     
    return res;
}

bool sortcolx(const vector<int>& v1, const vector<int>& v2 ) { 
    return v1[0] < v2[0]; 
} 

bool sortcoly(const vector<int>& v1, const vector<int>& v2 ) { 
    return v1[1] < v2[1]; 
} 

float dist(vec_v a)
{
   return sqrt(pow(a[0][0] - a[1][0], 2) + pow(a[0][1] - a[1][1], 2));
}


int main()
{
    int n;
    cin >> n;
    vec_v a(n, vec(2));
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];

    vec_v res = closePair(a);
    cout << "Closest pair: " << endl;
    cout << "(" << res[0][0] << ", " << res[0][1] << ")" << endl;
    cout << "(" << res[1][0] << ", " << res[1][1] << ")" << endl;

    return 0;
}
