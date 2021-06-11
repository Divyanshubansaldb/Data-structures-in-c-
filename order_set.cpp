#include<bits/stdc++.h>
using namespace std;

//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
#define int long long

//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ld long double
#define endl "\n"
const int mod=998244353;
const int MAX=100005;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int bit=31;

void solve(){
    int n;
    cin>>n;
    ordered_set st;