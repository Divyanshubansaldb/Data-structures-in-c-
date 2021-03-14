ll fun(int n, int r) 
{
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1; 
    return p;
}

//////////////////////////
/////////////////////////
// Extra

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

/////////////////////////
/////////////////////////
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007

const int maxn=1e5+1;
ll f[maxn];

ll pow(ll val, ll exp, ll MOD)
{
    ll x=1,y=val; 
    while(exp > 0)
    {
        if(exp%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        exp /= 2;
    }
    return x;
}
ll InverseEuler(ll n, ll MOD)
{
    return pow(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

void compute(int mod)
{
    f[0] = 1;
	for(int i = 1 ; i < maxn ; i++)
		f[i] = (f[i-1]*i)%mod;
}
int main()
{
    compute(MOD);
 	cout << C(100000,100,MOD) << endl;
}

// you can also use the property of (n,r) = (n-1,r) + (n-1,r-1); where (n,r) == nCr;
// using dynamic programming you can store the values and then calculate using recursion