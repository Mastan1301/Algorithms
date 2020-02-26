/*
    Topological sorting of an undirected graph using DFS.
    Time complexity: O(N+E)
*/

#include<bits/stdc++.h>
using namespace std;

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/

//static int s = 0;

void DFS(int s, vector<int> adj[], bool vis[], int* curr, int arr[])
{
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); i++)
    {
        if(!vis[adj[s][i]])
            DFS(adj[s][i], adj, vis, curr, arr);
    }
    arr[*curr] = s;
    (*curr)--;
}

int* topoSort(int V, vector<int> adj[])
{
    int curr = V-1;
    int* arr = new int[V];
    bool vis[V] = {false};

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            DFS(i, adj, vis, &curr, arr);
        }        
    }
    return arr;
}


/*
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
/*bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}*/

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        for(auto i = 0; i < N; i++)
        {
            cout << res[i] << " ";
        }
        
        //cout<<check(N, res, adj)<<endl;
       
    }
}
