/*
    Problem statement: https://www.hackerrank.com/challenges/find-the-running-median/problem

    Time complexity: O(log(i)) for i^th computation of the median.
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void computeMedian(int* arr, int n)
{
    priority_queue<int, vector<int>, less<int>> low_heap;
    priority_queue<int, vector<int>, greater<int>> high_heap;
    cout << fixed;
    cout << setprecision(1);

    for(int s = 1; s <= n; s++)
    {
        int val = arr[s-1];

        if(low_heap.size() < high_heap.size())
        {
            low_heap.push(val);
        }

        else
        {
            high_heap.push(val);
        }

        if(s > 1)
            if(low_heap.top() > high_heap.top())
            {
                int temp = low_heap.top();
                low_heap.pop();
                low_heap.push(high_heap.top());
                high_heap.pop();
                high_heap.push(temp);
            }

        if(s % 2)
        {
            cout << float(high_heap.top()) << endl;
        }

        else
        {
            cout << (low_heap.top()+high_heap.top())/2.0 << endl;
        }
    }       
}

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    computeMedian(arr, n);

    return 0;
}