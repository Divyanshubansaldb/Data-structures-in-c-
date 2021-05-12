#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M=1e9+7;

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

///////////////////
///////////////////

ll powerr(ll value,ll exp,ll modo)
{
    if(exp==0)
    {
        return 1;
    }
    else if(exp==1)
    {
        return value;
    }
    else
    {
        ll r=powerr(value,exp/2,modo)%modo;
        if(exp%2==0)
        {
            return((r*r)%modo);
        }
        else
        {
            ll temp=r*value;
            temp=temp%modo;
            temp=temp*r;
            return(temp%modo);
        }
    }
}