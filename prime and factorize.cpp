// a number bigger than 1e9 and is a prime number is 1777777777

bool isPrime(int n) 
{
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

void factorize(long long n,vector<int>& v) 
{ 
    int count = 0; 
  
    while (!(n % 2)) { 
        n >>= 1;
        count++; 
    } 
  
    if (count) 
    {
        v.pb(2);
    }
  
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
        {
            v.pb(i);
        }
    } 
  
    if (n > 2) 
    {
        v.pb(n);
    }
}

//////////////////////////////
//Print all prime factors and their powers
//////////////////////////////

void factorize(long long n,vector<pair<ll,ll>>&a) 
{
    int count = 0; 
    while (!(n % 2)) { 
        n >>= 1;
        count++; 
    }
    if (count) 
        a.eb(mk(2,count));
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0;
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count)
            a.eb(mk(i,count));
    }
    if (n > 2) 
        a.eb(mk(n,1));
}

///////////////////
///////////////////
const int MAXN=1e7+5;

int spf[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    {
        if (spf[i] == i) 
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}