/*
    Heap Sort 
    Time complexity: O(n*log(n))
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

void heapify(int arr[], int n, int i)  {
    int l = 2*i+1;
    int r = 2*i+2;
    int max_index = i;
    
        if(l < n && arr[max_index] < arr[l])
        {
            max_index = l;
        }

        if(r < n && arr[max_index] < arr[r])
        {
            max_index = r;
        } 

        if(max_index != i)
        {
            swap(arr[max_index], arr[i]);
            heapify(arr, n, max_index);
        }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    for(int i = n/2-1; i >=0; i--)
        heapify(arr, n, i);
}
