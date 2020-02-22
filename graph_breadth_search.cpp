/* 
    Breadth-first search for an undirected graph with m edges and n verctices.
    Time complexity: O(m+n)
*/

#include <bits/stdc++.h>
using namespace std;
typedef map<int, vector<int>> mint;
typedef vector<int> vint;

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
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}
