typedef struct segmenttree
{
private:
    ll n;
    vector<ll> lo,hi,delta,mn;
    
    void init(ll i,ll a,ll b)
    {
        lo[i]=a;hi[i]=b;
        if(a==b)
            return;
        ll mid=(a+b)/2;
        init(2*i, a,mid);
        init(2*i+1, mid+1, b);
    }

    void prop(ll i)
    {
        delta[2*i]+=delta[i];
        delta[2*i+1]+=delta[i];
        delta[i]=0;
    }

    void update(ll i)
    {
        mn[i]=min(mn[2*i]+delta[2*i],mn[2*i+1]+delta[2*i+1]);
    }
    
    void myincrement(ll i,ll a,ll b,ll val)
    {
        if(hi[i]<a || lo[i]>b)
            return;
        if(a<=lo[i] && hi[i]<=b)
        {
            delta[i]+=val;
            return;
        }

        prop(i);

        myincrement(2*i,a,b,val);
        myincrement(2*i+1,a,b,val);

        update(i);
    }

    ll minimum(ll i,ll a,ll b)
    {
        if(hi[i]<a || lo[i]>b)
            return LL_MAX;
        if(a<=lo[i] && hi[i]<=b)
            return delta[i]+mn[i];
        
        prop(i);
        ll temp=min(minimum(2*i,a,b),minimum(2*i+1,a,b));
        update(i);
        return temp;
    }

public:
    segmenttree() {}

    segmenttree(ll n): n(n)
    {
        lo.resize(4*n+1,0);
        hi.resize(4*n+1,0);
        delta.resize(4*n+1,0);
        mn.resize(4*n+1,0);
        init(1,0,n-1);
    }

    void increment(ll a,ll b,ll val)
    {
        myincrement(1,a,b,val);
    }

    ll rangemin(ll a,ll b)
    {
        return minimum(1,a,b);
    }
}segtree;

////////////////////////////////////////
// new segment tree
////////////////////////////////////////

typedef struct segmenttree
{
private:
    int n;
    vector<int> lo,hi,delta,mn;
    
    void init(int i,int a,int b)
    {
        lo[i]=a;hi[i]=b;
        if(a==b)
            return;
        int mid=(a+b)/2;
        init(2*i, a,mid);
        init(2*i+1, mid+1, b);
    }

    void prop(int i)
    {
        delta[2*i]+=delta[i];
        delta[2*i+1]+=delta[i];
        delta[i]=0;
    }

    void update(int i)
    {
        mn[i]=min(mn[2*i]+delta[2*i],mn[2*i+1]+delta[2*i+1]);
    }
    
    void myincrement(int i,int a,int b,int val)
    {
        if(hi[i]<a || lo[i]>b)
            return;
        if(a<=lo[i] && hi[i]<=b)
        {
            delta[i]+=val;
            return;
        }

        prop(i);

        myincrement(2*i,a,b,val);
        myincrement(2*i+1,a,b,val);

        update(i);
    }

    int minimum(int i,int a,int b)
    {
        if(hi[i]<a || lo[i]>b)
            return INT_MAX;
        if(a<=lo[i] && hi[i]<=b)
            return delta[i]+mn[i];
        
        prop(i);
        int temp=min(minimum(2*i,a,b),minimum(2*i+1,a,b));
        update(i);
        return temp;
    }

public:
    segmenttree() {}
    segmenttree(int n): n(n)
    {
        lo.resize(4*n+1,0);
        hi.resize(4*n+1,0);
        delta.resize(4*n+1,0);
        mn.resize(4*n+1,0);
        init(1,0,n-1);
    }

    void increment(int a,int b,int val)
    {
        myincrement(1,a,b,val);
    }

    int rangemin(int a,int b)
    {
        return minimum(1,a,b);
    }
}segtree;


/////////////////////////
// old segment tree
//////////////////////////
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

////////////////

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

///////////////////

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}