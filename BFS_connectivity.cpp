/*
    Determine the connectivity of a directed graph.
    Time complexity: O(N+E)
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> q;
    q.push(s);
    //cout << adj[s][0];
    cout << s << " ";
    vis[s] = true;
    int i = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < adj[v].size(); i++)
            if(!vis[adj[v][i]])
            {
                q.push(adj[v][i]);
                cout << adj[v][i] << " ";
                vis[adj[v][i]] = true;
            }
    } 
    cout << endl;   
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            
        }
        for(int i = 0; i < E; i++)
        {
            vis[N] = {false};
            bfs(i, adj, vis, N);
        }
    }
}