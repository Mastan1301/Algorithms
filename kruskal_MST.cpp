#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int findPar(int parent[], int x)
{
    if(parent[x] == x) return x;

    parent[x] = findPar(parent, parent[x]);
    return parent[x];
}

void Union(int parent[], int x, int z){
    int parX = findPar(parent, x), parZ = findPar(parent, z);

    if(x != z){
        parent[parZ] = parX;
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    int m = g_weight.size(); 
    vector<int> V(m);
    int x = 0;
    std::iota(V.begin(),V.end(),x++); //Initializing V
    sort( V.begin(),V.end(), [&](int i,int j){return g_weight[i]<g_weight[j];} );

    vector<int> temp1(g_from.begin(), g_from.end());
    vector<int> temp2(g_to.begin(), g_to.end());
    vector<int> temp3(g_weight.begin(), g_weight.end());

    vector<int> mst;

    for(int i = 0; i < m; i++)
    {
        g_from[i] = temp1[V[i]];
        g_to[i] = temp2[V[i]];
        g_weight[i] = temp3[V[i]];
    }

    int parent[g_nodes+1], rnk[g_nodes+1];

    for(int i = 1; i < g_nodes+1; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }

    for(int i = 0; i < m; i++){
        if(findPar(parent, g_from[i]) != findPar(parent, g_to[i]))
         {
            mst.push_back(g_weight[i]);
            Union(parent, g_from[i], g_to[i]);
         }   
    }

    return accumulate(mst.begin(), mst.end(), 0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res;
    cout << res << endl;
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
