const ll maxn = 8e5+5;
ll D =floor(log2(maxn));
ll n;

vector<vector<ll>> table(maxn, vector<ll> (D+1,-1));
vector<ll> depth(maxn,0);
vector<ll> visited(maxn,0);
vector<vector<ll>> graph(maxn);
void bfs(ll x=1)
{
    queue<ll> q;
    q.push(x);
    while(!q.empty())
    {
        ll temp=q.front();
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
    for (ll i = 1; i <= D; i++)
    {
        for (ll j = 1; j < n+1; j++)
        {
            ll mid=table[j][i-1];
            if(mid!=-1)
                table[j][i]=table[mid][i-1];
        }
    }
}

ll walk(ll j,ll k)
{
    for (ll i = 0; i <= D && j!=-1; i++)
    {
        if((1<<i & k) >0)
        {
            j=table[j][i];
        }
    }
    return j;
}

ll lca(ll u,ll v)
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
    
    for (ll i = D; i >= 0; i--)
    {
        if(table[u][i]!=table[v][i])
        {
            u=table[u][i];
            v=table[v][i];
        }
    }
    
    return table[u][0];
}

ll distance(ll u,ll v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

void solve()
{
    cin>>n;

    for(int i=0;i<=n;i++){
        table[i][0] = 0;
        depth[i] = 0;
        visited[i] = 0;
        graph[i].clear();
    }

    bfs();
    makingtable();

}

// use range minimum queries for finding lca
// use the concept of euler walk 
// first -> linearize the complete graph in an array using using preorder and postorder numbers
// second -> put the corresponding elements in the array and height of the elements
// then use a suitable data structure for finding the minimum height in this array in a given range 
// then solve for query pairs 
// find their preorder number and then find the minimum elements between the range of preorder number
// the element corresponding to that minimum value will be the lca. So use binarysearch to compute the element.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define LL_MAX LLONG_MAX
#define ULL_MAX ULLONG_MAX
#define ull unsigned long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(x) int(x.size())
#define endl '\n'
#define LOCAL
#ifdef LOCAL
    #define deb(x) cout<<#x<<" "<<x<<" ";
    #define debendl(x) cout<<#x<<" "<<x<<endl;
#else
    #define deb(...) 1
    #define debendl(...) 1
#endif
const ll maxn = 2e5+5;
const ll LOG = 20;
ll n;

vector<vector<ll>> graph(maxn);
vector<vector<ll>> orders(maxn);
vector<vector<ll>> table(LOG, vector<ll> (3*maxn,0));
vector<ll> bin_logs(3*maxn,0);
vector<vector<ll>> idx(LOG, vector<ll> (3*maxn,0));

ll preorder = 1;

void dfs(ll x, ll p, ll h){
    idx[0][preorder] = x;
    table[0][preorder] = h;
    orders[x].push_back(preorder);
    preorder++;

    for(ll it: graph[x]){
        if(it == p) continue;
        dfs(it,x, h+1);
        idx[0][preorder] = x;
        table[0][preorder] = h;
        orders[x].push_back(preorder);
        preorder++;
    }
}


void log_compute(){
    for(int i=2;i<maxn;i++){
        bin_logs[i] = bin_logs[i/2]+1;
    }
}

void min_compute(){

    for(int i=1;i<=bin_logs[preorder];i++){
        for(int j=1;j+(1<<i)-1<preorder;j++){
            ll mid = j+(1<<(i-1));
            if(table[i-1][j] < table[i-1][mid]){
                table[i][j] = table[i-1][j];
                idx[i][j] = idx[i-1][j];
            }
            else{
                table[i][j] = table[i-1][mid];
                idx[i][j] = idx[i-1][mid];
            }

            table[i][j] = min(table[i-1][j], table[i-1][mid]);
        }
    }
}

ll query(ll a, ll b){
    if(a>b) swap(a,b);
    ll gap = bin_logs[b-a+1];

    if(table[gap][a] < table[gap][b-(1<<gap)+1]){
        return idx[gap][a];
    }
    else{
        return idx[gap][b-(1<<gap)+1];
    }
}

void solve()
{
    preorder = 1;
    cin>>n;

    for(int i=0;i<=n;i++){
        graph[i].clear();
        orders[i].clear();
    }
    for(int i=0;i<=3*n;i++){
        table[0][i] = 0;
        idx[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, -1, 0);

    log_compute();
    min_compute();
    
    ll q;
    cin>>q;

    while(q--){
        ll x,y;
        cin>>x>>y;
        ll indx = orders[x][0];
        ll indy = orders[y][0];

        cout<<query(indx,indy)<<endl;
    }
}

int main()
{
    IOS;
    ll t=1;
    cin>>t;
    ll i=1;
    while (t--)
    {
        cout<<"Case "<<i++<<":"<<endl;
        solve();
    }
}