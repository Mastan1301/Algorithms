#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
typedef vector<int>::iterator itr;

vector<int> digits(ll y) //to find the digits of a number
{
    vector<int> res;
    while(y)
    {
        res.push_back(y%10);
        y /= 10;
    }
    return res;
}

ll gradeSchool(ll x, ll y) //grade school multiplication algorithm
{
    ll res = 0;
    vector<int> dig_y = digits(y);
    ll shift = 1; //used as a multiplying/shifting facto
    for(itr i = dig_y.begin(); i != dig_y.end(); i++)
    {
        res += (*i) * x * shift;
        shift *= 10;
    }
    return res;
}

ll karatsuba(ll x, ll y)
{
    if()
}

int main()
{
    ll x, y;
    cin >> x >> y;
    cout << gradeSchool(x, y) << endl;
    //count << karatsuba(x, y) << endl;;
    return 0;
}
