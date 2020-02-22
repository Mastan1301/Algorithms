/*
    Shortest path in an undirected, unweighted graph from source vertex 's' to destination vertex 'd'.
    (Using BFS)
    Time complexity: O(N+E)
*/
#include <bits/stdc++.h>
using namespace std;
typedef map<int, vector<int>> mint;
typedef vector<int> vint;

int bfs(int s, vector<int> adj[], bool vis[], int N, int d)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    int depth[N] = {0};
    //int min = N;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < adj[v].size(); i++)
        {            
            if(!vis[adj[v][i]])
            {
                depth[adj[v][i]] = depth[v]+1;
                if(adj[v][i] == d)
                    return depth[adj[v][i]];
                q.push(adj[v][i]);
                //cout << adj[v][i] << " ";
                vis[adj[v][i]] = true;
            }
        }
    }

    return -1;    
}

//Note that the vertices are 0, 1, 2 .... n-1. And the source vertex is 0.
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
        int s = 0, d = 4; //source and destination respectively      
        cout << bfs(s, adj, vis, N, d) << endl;

    }
}
