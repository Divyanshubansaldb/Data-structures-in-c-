//Name - Divyanshu Bansal
//Roll number - 18UCC051
//Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Input the number of Vertices" << endl;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    vector<vector<int>> path(n + 1);
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

    int source;
    cout << "Enter the Source node" << endl;
    while (1)
    {
        cin >> source;
        if (source <= n)
            break;
        cout << "This is not a valid Source. Enter a valid Source node." << endl;
    }
    dist[source] = 0;
    set<pair<int, int>> q;
    q.insert({0, source});
    while (!q.empty())
    {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());
        for (auto it : graph[p.second])
        {
            if (p.first + it.second < dist[it.first])
            {
                q.erase({dist[it.first], it.first});
                dist[it.first] = p.first + it.second;
                path[it.first] = path[p.second];
                path[it.first].push_back(p.second);
                q.insert({dist[it.first], it.first});
            }
        }
    }

    cout << "Shortest distance from the source nodes are:-" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Node:- " << i << endl
             << "Distance - ";
        if (dist[i] == INT_MAX)
        {
            cout << "Infinite" << endl;
            continue;
        }
        else
            cout << dist[i] << endl;

        cout << "Path - ";
        for (int it : path[i])
            cout << it << " ";
        cout << i << endl;
        cout << endl;
    }
}