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

class kmp_algorithm{
public:
	vector<int> lps(string s)
	{
	    int n = s.size();
	    vector<int> pos(n,-1);
	    
	    int j = -1;
	    for(int i=1;i<n;i++){
	        while(j!=-1 && s[i]!=s[j+1]) j = pos[j];
	        if(s[i]==s[j+1]) j++;
	        pos[i]=j;
	    }

        return pos;
	}

    vector<int> kmp(string a, string b){
        vector<int> pos = lps(b);

        vector<int> ans;
        int j=-1;
        for(int i=0;i<a.size();i++){
            while(j!=-1 && a[i]!=b[j+1]) j = pos[j];
            if(a[i]==b[j+1]) j++;
            if(j==b.size()-1) ans.push_back(i-j);
        }

        return ans;
    }

};

void solve()
{
    string a, b; cin>>a>>b;
    kmp_algorithm s;
    vector<int> ans = s.kmp(a,b);
    for(int i: ans) cout<<i<<" ";
    cout<<endl;
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