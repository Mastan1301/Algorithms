// Problem statement: https://www.hackerrank.com/challenges/jesse-and-cookies/problem

#include <bits/stdc++.h>
using namespace std;


void showpq(priority_queue<int, vector<int>, greater<int>> heap)
{
    while(!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
}
int nop(int* arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(k);
    for(int i = 0; i < n; i++)
        heap.push(arr[i]);
    
    int count  = 0;
    while(heap.top() != k)
    {
        int t1 = heap.top();
        heap.pop();
        int t2 = heap.top();

        if(t2 != k)
            {heap.pop();
            heap.push(t1+(2*t2));
            count++;
            }
        else 
        {
            if(heap.size() > 2)
            {   
                heap.pop();
                heap.pop();
                t2 = heap.top();
                heap.push(t1+(2*t2));
                heap.push(k); 
                count++;
            }
            else
            {
                count = -1;
                break;
            }                       
        }

        //showpq(heap);
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << i << endl;
    }
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << nop(arr, n, k);

}