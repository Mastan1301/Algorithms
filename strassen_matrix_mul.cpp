/*Implementation of Strassen's Sub-cubic Matrix Multiplication
 using Divide and Conquer paradigm (recursion).
 Time complexity: O(n^2.807)

 Note: This algorithm is applicable for square matrices where 'n' is in the power of 2 only.
 For eg: for size = 2x2, 4x4, 8x8,.... 
 For any other sizes, appropriate padding of zeros will do the trick.*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> vec_v;

vec_v sub_mat(vec_v x, int start_x, int start_y, int size) //returns a sub-matrix
{
    vec_v res(size, vec(size));
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            res[i][j] = x[start_x+i][start_y+j];
    }
    return res;
}

vec_v sum(vec_v x, vec_v y) //returns the sum of two matrices
{
    int n1 = x.size();
    vec_v res(n1, vec(n1));
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n1; j++)
            res[i][j] = x[i][j]+y[i][j];

    return res;
}

vec_v sub(vec_v x, vec_v y) //subtracts two matrices
{
    int n1 = x.size();
    vec_v res(n1, vec(n1));
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n1; j++)
            res[i][j] = x[i][j]-y[i][j];

    return res;
}

vec_v stras_mul(vec_v x, vec_v y) //function for strassen sub-matrix multiplication
{
    int n = x.size();
    vec_v res(n, vec(n));
    if(n == 1)
    {
        res[0][0] = x[0][0]*y[0][0];
        return res;
    }
    vec_v a = sub_mat(x, 0, 0, n/2), b = sub_mat(x, 0, n/2, n/2), c = sub_mat(x, n/2, 0, n/2), d = sub_mat(x, n/2, n/2, n/2);
    vec_v e = sub_mat(y, 0, 0, n/2), f = sub_mat(y, 0, n/2, n/2), g = sub_mat(y, n/2, 0, n/2), h = sub_mat(y, n/2, n/2, n/2);
    vec_v p1  = stras_mul(a, sub(f,h));
    vec_v p2 = stras_mul(sum(a, b), h);
    vec_v p3 = stras_mul(sum(c, d), e);
    vec_v p4 = stras_mul(d, sub(g, e));
    vec_v p5 = stras_mul(sum(a, d), sum(e, h));
    vec_v p6 = stras_mul(sub(b, d), sum(g, h));
    vec_v p7 = stras_mul(sub(a, c), sum(e, f));

    vec_v t1 = sub(sum(p5, p4), sub(p2, p6)), t2 = sum(p1, p2), t3 = sum(p3, p4), t4 = sub(sum(p1, p5), sum(p3, p7));

    for(int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < n/2; j++)
            res[i][j] = t1[i][j];
    }  

    for(int i = 0; i < n/2; i++)
    {
        for(int j = n/2; j < n; j++)
            res[i][j] = t2[i][j-n/2];
    }  

    for(int i = n/2; i < n; i++)
    {
        for(int j = 0; j < n/2; j++)
            res[i][j] = t3[i-n/2][j];
    }  

    for(int i = n/2; i < n; i++)
    {
        for(int j = n/2; j < n; j++)
            res[i][j] = t4[i-n/2][j-n/2];
    } 

    return res;   
}

int main()
{
    int n;
    cin >> n;
    vec_v a(n, vec(n)), b(n, vec(n));

    for(int i = 0; i < n; i++)
    {    
       for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < n; i++)
    {    
       for(int j = 0; j < n; j++)
            cin >> b[i][j];
    }

    vec_v res = stras_mul(a, b);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << res[i][j] << " ";

        cout << endl;
    }

    return 0;
}
