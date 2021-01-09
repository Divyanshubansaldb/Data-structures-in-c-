#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define LL_MAX LLONG_MAX
#define ULL_MAX ULLONG_MAX
#define ull unsigned long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb(x) push_back(x)
#define re() pop_back()
#define eb(x) emplace_back(x)
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define all(a) a.begin(), a.end()
#define msort(a) sort(a.begin(), a.end())
#define pii pair<int, int>
#define sz(x) int(x.size())
#define mk make_pair
#define endl '\n'
#define debug 1
#ifdef debug
#define deb(x) cout << #x << " " << x << " ";
#else
#define deb(x) 1
#endif

class trie
{
public:
    // vector<trie *> child = vector<trie *>(2, NULL);
    int count = 0;
    trie *child[2] = {NULL};
};

void addingnumber(trie *root, int n)
{
    for (int i = 31; i >= 0; i--)
    {
        bool d = 1 << i & n;
        if (!root->child[d])
        {
            root->child[d] = new trie();
        }

        root = root->child[d];
        root->count++;
    }
}

int sum = 0;

void countpair(trie *root, int n, int k, int i)
{

    if (i < 0)
        return;

    if (!root)
        return;

    // deb(root->count) deb(n) deb(k) deb(i)
    //         cout
    //     << endl;
    // trie *root1 = root->child[0], *root2 = root->child[1];
    // if (root->child[0] == NULL && root->child[1] == NULL)
    //     return;

    bool b1 = 1 << i & n;
    bool b2 = 1 << i & k;
    if (b2)
    {
        if (b1)
            countpair(root->child[1], n, k, i - 1);
    }
    else
    {
        if (b1 && root->child[1])
            sum += root->child[1]->count;
        if (!b1)
            countpair(root->child[1], n, k, i - 1);
        countpair(root->child[0], n, k, i - 1);
    }
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((a[i] & a[j]) > k)
                ans++;
        }
    }
    cout << ans << endl;
    // return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    long long ans = 0;
    trie *root = new trie();
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        countpair(root, a[i], k, 31);
        ans += sum;
        addingnumber(root, a[i]);
    }

    // return ans;
    cout << ans;
}

int main()
{
    IOS;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}