/*
    Strongly Connected components in a directed graph.
    Time Complexity: O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

static int s = 0, t = 0;

void DFS(int source, vector<int> adj[], bool vis[], int f[])
{
    vis[source] = true;

    if(!adj[source].size())
        return;

    for(int i = 0; i < adj[source].size(); i++)
    {
        if(!vis[adj[source][i]])
            DFS(adj[source][i], adj, vis, f);
    }    
    t++;
    f[source] = t;
}

void DFS_1(int source, vector<int> adj[], bool vis[], int leader[])
{
    vis[source] = true;
    leader[source] = s;
    if(!adj[source].size())
        return;

    for(int i = 0; i < adj[source].size(); i++)
    {        
        if(!vis[adj[source][i]])
            DFS_1(adj[source][i], adj, vis, leader);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    bool vis_rev[V] = {false};
    t = 0;
    vector<int> adj_rev[V];
    int f[V] = {0};
    
    for(int i = 0; i < V; i++) //reversing the graph
    {
        for(int j = 0; j < adj[i].size(); j++)
        {   
            adj_rev[adj[i][j]].push_back(i);
        }
    }

    for(int i = V-1; i >= 0; i--)
    {
        if(!vis_rev[i])
        {
            DFS(i, adj_rev, vis_rev, f);
        }
    }

    vector<int> adj_time[V+1];

    for(int i = 0; i < V; i++) 
    {
        for(int j = 0; j < adj[i].size(); j++)
        {   
            adj_time[f[i]].push_back(f[adj[i][j]]);
        }
    }

    bool vis[V+1] = {false};
    int leader[V+1];
    for(int i = V; i > 0; i--)
    {
        if(!vis[i])
        {
            s = i;
            leader[s] = s;
            DFS_1(i, adj_time, vis, leader);
        }
    }

    set<int> t1;
    for(int i = 1; i < V+1; i++)
    {
        t1.insert(leader[i]);
    }
    
    return t1.size();
}

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ; //a = vertices, b = edges
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}