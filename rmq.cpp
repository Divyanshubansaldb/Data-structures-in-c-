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

const int LOG = 20;
const int maxn = 2e5+5;

vector<vector<int>> table(LOG, vector<int>(maxn,INT_MAX));

void solve()
{
    int n; cin>>n;
    int q; cin>>q;

    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        table[0][i] = a[i];
    }

    vector<int> bin_log(n+1,0);
    bin_log[1] = 0;

    for(int i=2;i<=n;i++){
        bin_log[i] = bin_log[i/2] +1;
    }

    for(int i=1;i<=bin_log[n];i++){
        int jump = 1<<(i-1);
        for(int j=0;j+(1<<i)-1<n;j++){
            table[i][j] = min(table[i-1][j] , table[i-1][j+jump]);
        }
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;

        int gap = r-l+1;

        int jump = bin_log[gap];
        
        cout<<min(table[jump][l] , table[jump][r-(1<<jump)+1])<<endl;
    }
}

int main()
{
    IOS;
    ll t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}