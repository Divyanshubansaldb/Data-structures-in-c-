ll hashvalue(string &s,ll p,ll x)
{
    ll temp=0;
    for (ll i = 0; i < s.size(); i++)
    {
        temp+=s[i]*power(x,i,p);
        temp%=p;
    }
    return temp;
}