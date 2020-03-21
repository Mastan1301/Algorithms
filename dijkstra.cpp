/*
    Shortest path using Dijkstra's algorithm in a weighted, undirected graph.
    Time complexity: O(m*log(n)) (for a sparse graph)
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef pair<int, int> iPair;
typedef priority_queue<iPair, vector<iPair>, greater<iPair>> P_QUEUE;

#define inf INT_MAX

void shortestPath(int** edges, int source, int n, int m)
{
    int* A = new int[n+1];
    for(int i = 0; i < n+1; i++)
        A[i] = inf;

    P_QUEUE pq; //min-Heap using priority_queue
    pq.push(make_pair(0, source));
    bool checks[n+1] = {false};

    A[source] = 0;

    int v, w;
    while(!pq.empty())
    {
        v = pq.top().second;
        checks[v] = true;
        pq.pop();

        for(int i = 0; i < m; i++)
        {
            if(edges[i][1] == v && !checks[edges[i][0]])
            {
                w = edges[i][0];
                int l_vw = edges[i][2];

                if(A[w] > A[v]+l_vw)
                {
                    A[w] = A[v] + l_vw; 
                    pq.push(make_pair(A[w], w)); 
                }
            }

            if(edges[i][0] == v && !checks[edges[i][1]])
            {
                w = edges[i][1];
                int l_vw = edges[i][2];

                if(A[w] > A[v]+l_vw)
                {
                    A[w] = A[v] + l_vw; 
                    pq.push(make_pair(A[w], w)); 
                }
            }
        }
        //showpq(pq);
    } 

    for(int i = 1; i < n+1; i++) 
        {
            if(i != source)
            {
                if(A[i] == inf)
                    cout << -1 << " ";

                else
                    cout << A[i] << " ";
            }
        }
         
    cout << endl;   
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m; //no. of vertices and no. of edges
        cin >> n >> m;
        int** edges = new int*[m];

        for(int i = 0; i < m; i++)
        {
            edges[i] = new int[3];
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }  
                
        int source;
        cin >> source;
        
        shortestPath(edges, source, n, m); 
         
    }

    return 0;
}