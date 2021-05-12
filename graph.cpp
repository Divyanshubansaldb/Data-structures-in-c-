int N=3e5+5;

vector<vector<int>> graph(N);
vector<int> visited(N,0);

void dfs(int x,int p)
{
    for(int i: graph[x])
    {
        if(i==p)
            continue;
        dfs(i,x);
    }
}

void inpgraph(int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].eb(y);
        graph[y].eb(x);
    }
}

void bfs(int n)
{
    vector<bool> vis(n+1,0);
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i: graph[x])
        {
            if(vis[i])
                continue;
            q.push(i);
            vis[i]=1;
        }
    }
}