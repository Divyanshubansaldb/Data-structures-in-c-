//Name - Divyanshu Bansal
//Roll number - 18UCC051
//Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int u, v, weight;
};

int main()
{
    int n;
    cout << "Input the number of Vertices" << endl;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<pair<int, int>> parent(n + 1, {INT_MAX, INT_MAX});
    vector<edge> mst;
    int ans = 0;

    int m;
    cout << "Input the number of edges" << endl;
    cin >> m;
    cout << "Input the edge in the format=> u v weight" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    set<pair<int, int>> q;
    q.insert({0, 1});
    vector<int> visited(n + 1, 0);
    while (!q.empty())
    {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());
        visited[p.second] = 1;
        if (p.second != 1)
        {
            ans += p.first;
            edge e;
            e.u = parent[p.second].second;
            e.v = p.second;
            e.weight = p.first;
            mst.push_back(e);
        }

        for (auto it : graph[p.second])
        {
            if (visited[it.first])
                continue;
            if (parent[it.first].first > it.second)
            {
                q.erase({parent[it.first].first, it.first});
                parent[it.first] = {it.second, p.second};
                q.insert({parent[it.first].first, it.first});
            }
        }
    }

    cout << "Details for the Minimum Spanning Tree of the graph is:-" << endl;
    cout << "Weight of the tree:- " << ans << endl;
    cout << "Edges included in the tree:-" << endl;
    for (auto it : mst)
    {
        cout << it.u << "-" << it.v << "\t Weight-" << it.weight << endl;
    }
}