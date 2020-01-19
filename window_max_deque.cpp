#include <iostream>
#include <deque>
#include <cstdio> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> q;
    int i = 0;
    for(int i = 0; i < k; i++)
    {
        while((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    for(; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while((!q.empty()) && q.front() <= i-k) //pop the indices outside the window
            q.pop_front();

        while((!q.empty() && arr[i] >= arr[q.back()]))
            q.pop_back();
        
        q.push_back(i);
    }

    cout << arr[q.front()] << endl;
}

int main(){
  
    int t;
    scanf("%d", &t);
    while(t>0) {
        int n,k;
        scanf("%d%d", &n, &k);
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

