//Karatsuba multiplication algorithm using recursion
//Time complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;
//typedef long long int ll;

string add(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length(), carry = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
    string res;
    int i, j, temp;

    for(i = 0, j = 0; (i < n1 && j < n2);)
    {
        temp = int(s1[i]) +int(s2[i]) - (2*int('0'))+carry;
		//cout << "Temp = " << temp << endl;
		carry = temp/10;
        res = res + to_string(temp%10);
		//cout << "res = " << res << endl;
		i++;
		j++;
    }

    while(i < n1)
    {
		temp = int(s1[i]) - int('0') + carry;
		carry = temp/10;
        res = res + to_string(temp%10);
        i++;
    }

    while(j < n2)
    {
		temp = int(s2[j]) - int('0') + carry;
		carry = temp/10;
        res = res + to_string(temp%10);
        j++;
    }
	res = res+to_string(carry);
	reverse(res.begin(), res.end());
    return res;
}

string karatsuba(string x, string y)
{
    int size = x.length(), n;
    if(size == 1)
        return to_string((int(x[0])-int('0'))*(int(y[0]) - int('0')));
    
    string a = x.substr(0, size/2);
    string b = x.substr(size/2, size-size/2);
    string c = y.substr(0, size/2);
    string d = y.substr(size/2, size-size/2);
    string s1, s2;

    for(int i = 0; i < size + (size%2); i++)
        s1 = s1+'0';
    for(int i = 0; i < a.length(); i++)
        s2 = s2+'0';

    string ac = karatsuba(a, c), bd = karatsuba(b, d), adbc = add(karatsuba(a, d), karatsuba(b, c));
    /*cout << "ac = " << ac << endl;
    cout << "adbc = " << adbc << endl;
    cout << "bd = " << bd << endl;*/
    string res = add(ac+s1, add(bd, adbc+s2));
    return res;
}

string remov_zeros(string s)
{
    int pos = 0;
    while(s[pos] == '0') {
      pos++;
   }
   s.erase(0, pos);
   return s;
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << remov_zeros(karatsuba(x, y)) << endl;
    return 0;
}
