/*
    Depth first search of an undirected graph.
    Time complexity: O(N+E)
*/

#include<bits/stdc++.h>
using namespace std;

/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/

//recursive approach
void dfs_r(int s, vector<int> g[], bool vis[])
{
    cout << s << " ";
    vis[s] = true;
    if(g[s].size() == 0)
        return;

    for(int i = 0; i < g[s].size(); i++)
    {
        if(!vis[g[s][i]])
            dfs_r(g[s][i], g, vis);
    }
}

//iterative approach
/*void dfs_i(int s, vector<int> g[], bool vis[])
{
    stack<int> t;
    t.push(s);
    vis[s] = true;
    cout << s << " ";
    while(!t.empty())
    {
        int temp = t.top();
        t.pop();
        for(int i = 0; i < g[temp].size(); i++)
        {
            if(!vis[g[temp][i]])
            {
                cout << g[temp][i] << " ";
                vis[g[temp][i]] = true;  
                t.push(g[temp][i]);            
            }
        }
    }
}*/

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs_r(0,g,vis);
        
        cout<<endl;

    }
}  