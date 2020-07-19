int n;
int D=floor(log2(n));

vector<vector<int>> table(n+1, vector<int> (D+1,-1));
vector<int> depth(n+1,0);
vector<int> visited(n+1,0);
vector<vector<int>> graph(n+1);
void bfs(int x=1)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        visited[temp]=1;
        for (auto &&i : graph[temp])
        {
            if(visited[i]==1)
                continue;
            q.push(i);
            depth[i]=depth[temp]+1;
            table[i][0]=temp;
        }
    }
}

void makingtable()
{
    for (int i = 1; i <= D; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            int mid=table[j][i-1];
            if(mid!=-1)
                table[j][i]=table[mid][i-1];
        }
    }
}

int walk(int j,int k)
{
    for (int i = 0; i <= D && j!=-1; i++)
    {
        if((1<<i & k) >0)
        {
            j=table[j][i];
        }
    }
    return j;
}

int lca(int u,int v)
{
    if(depth[u]>depth[v])
    {
        u=walk(u,depth[u]-depth[v]);
    }
    else
    {
        v=walk(v,depth[v]-depth[u]);
    }
    
    if(u==v)
        return u;
    
    for (int i = D; i >= 0; i--)
    {
        if(table[u][i]!=table[v][i])
        {
            u=table[u][i];
            v=table[v][i];
        }
    }
    
    return table[u][0];
}

int distance(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}