#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
#define inf 1000000
vector<string> split_string(string);

int minimum(int x, int y)
{
    if(x < y)
        return x;
    return y;
}
// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> heap;

    bool vis[n+1] = {false};
    int v, w, m = edges.size();
    int cost[n+1];
    for(int i = 1; i < n+1; i++)
        cost[i] = inf;

    int sum = 0;

    heap.push(make_pair(0, start));

    while(!heap.empty())
    {
        v = heap.top().second;
        int temp = heap.top().first;
        heap.pop();
        //cout << v ;
        if(!vis[v])
        {
            //cout <<v << endl;
            sum +=temp;
            vis[v] = true;       

            for(int i = 0; i < m; i++)
            {
                if(edges[i][1] == v && vis[edges[i][0]] == false)
                {
                    w = edges[i][0];
                    cost[w] = min(cost[w], edges[i][2]);                
                    heap.push(make_pair(cost[w], w));
                    //cout << w << endl;
                }

                else if(edges[i][0] == v && vis[edges[i][1]] == false)
                {
                    w = edges[i][1];
                    cost[w] = min(cost[w], edges[i][2]);                
                    heap.push(make_pair(cost[w], w));
                    //cout << endl;
                }
            }
        }

        
    } 

    cout << sum << "\n";
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
