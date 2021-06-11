#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define LL_MAX LLONG_MAX
#define ULL_MAX ULLONG_MAX
#define ull unsigned long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb(x) push_back(x)
#define re() pop_back()
#define eb(x) emplace_back(x)
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define all(a) a.begin(),a.end()
#define msort(a) sort(a.begin(),a.end())
#define pii pair<int,int>
#define sz(x) int(x.size())
#define mk make_pair
#define endl '\n'
#define LOCAL
#ifdef LOCAL
    #define deb(x) cout<<#x<<" "<<x<<" ";
    #define debendl(x) cout<<#x<<" "<<x<<endl;
#else
    #define deb(...) 1
    #define debendl(...) 1
#endif

const int maxn = 1005;
vector<int> cost(maxn,INT_MAX);

struct sortingset{
    bool operator()(int a, int b) const{
        return make_pair(cost[a],a) < make_pair(cost[b],b);
    }
};

class Solution
{
	public:
    
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        fill(cost.begin(),cost.end(),INT_MAX);
        int finalcost = 0;
        vector<int> parent(v,-1);
         
        set<int, sortingset> s;
        
        cost[0] = 0;
        s.insert(0);
        
        for(int i=1;i<v;i++){
            s.insert(i);
        }
        
        for(int it: s) cout<<it<<" ";
        cout<<endl;
        while(!s.empty()){
            int node = *s.begin();
            s.erase(node);
            
            finalcost+=cost[node];
            for(auto it: adj[node]){
                int child = it[0], weight = it[1];
                if(s.count(child) && cost[child]>weight){
                    s.erase(child);
                    parent[child] = node;
                    cost[child] = weight;
                    s.insert(child);
                }
            }
        }
        
        return finalcost;
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj[n];
    
    for (int i = 0; i < n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int> temp = {v,w};
        adj[u].push_back(temp);
        temp = {u,w};
        adj[v].push_back(temp);
    }
    
    Solution obj;
    cout<<obj.spanningTree(n,adj)<<endl;

}

int main()
{
    IOS;
    int t=1; //cin>>t;
    while (t--)
    {
        solve();
    }
}