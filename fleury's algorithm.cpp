//Name - Divyanshu Bansal
//Roll number - 18UCC051
//Fleury's Algorithm

#include <bits/stdc++.h>
using namespace std;

class data
{
public:
    int u, v;
    string name;
};

void dfs(vector<vector<pair<int, string>>> &graph, vector<bool> &visited, int source)
{
    visited[source] = 1;
    for (auto it : graph[source])
    {
        if (visited[it.first])
            continue;
        dfs(graph, visited, it.first);
    }
}

void myremove(vector<pair<int, string>> &a, int ele)
{
    int n = a.size();
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (a[i].first == ele)
        {
            ind = i;
            break;
        }
    for (int i = ind; i < n - 1; i++)
        a[i] = a[i + 1];
    a.pop_back();
}

int main()
{
    int n;
    cout << "Input the number of Vertices" << endl;
    cin >> n;
    vector<vector<pair<int, string>>> graph(n + 1);
    int m;
    cout << "Input the number of edges" << endl;
    cin >> m;
    cout << "Input the edge in the format=> u v EdgeName" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        graph[x].push_back({y, s});
        graph[y].push_back({x, s});
    }

    int start = 1;
    {
        //Check if the graph is euler or not;
        int oddvertices = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((int)graph[i].size() & 1)
                oddvertices++, start = i;
        }

        if (oddvertices == 0 || oddvertices == 2)
        {
            cout << "Euler line is possible" << endl;
        }
        else
        {
            cout << "Euler line is not possible" << endl;
            return 0;
        }
    }
    vector<bool> visited(n + 1, 0);
    vector<data> euler;
    while (m--)
    {
        for (auto it : graph[start])
        {
            vector<vector<pair<int, string>>> withoutgraph = graph;
            myremove(withoutgraph[it.first], start);
            myremove(withoutgraph[start], it.first);

            fill(visited.begin(), visited.end(), 0);
            dfs(graph, visited, start);
            int beforeremoving = count(visited.begin(), visited.end(), 1);

            fill(visited.begin(), visited.end(), 0);
            dfs(withoutgraph, visited, start);
            int afterremoving = count(visited.begin(), visited.end(), 1);

            if (afterremoving != beforeremoving && graph[start].size() > 1)
                continue;

            data temp;
            temp.u = start, temp.v = it.first, temp.name = it.second;
            euler.push_back(temp);
            graph = withoutgraph;
            start = it.first;
            break;
        }
    }

    cout << "Euler line formed by Fleury's algorithm is:-" << endl;
    for (auto it : euler)
        cout << it.u << " " << it.name << " ";
    cout << euler.back().v;
}