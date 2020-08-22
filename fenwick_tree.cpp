// if you want range update and point query than have to do more update queries
// in this case the prefix sum will give us the point query
// for update let's say you have a range
// 1 2 3 4 5 6 7 8
// 0 0 0 0 0 0 0 0 are initial values and you want to update them so that you have value 5 in the range [3,6]
// 0 0 5 5 5 5 0 0 so to make this you have to make the following queries:-update(3(index from where start),5)
// update(7(the ending position + 1), -5(negative of the value you want to add));
update(3,5);
update(7,-5);
////////
////////
struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n+1;
        bit.assign(n+1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) 
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i+1, a[i]);
    }

    int sum(int r)
    {
        r++;
        int ret = 0;
        while(r>0)
        {
            ret+=bit[r];
            r-=r&-r;
        }
        return ret;
    }

    int sum(int l, int r) 
    {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) 
    {
        while(idx<n)
        {
            bit[idx]+=delta;
            idx+=idx&-idx;
        }
    }
};


////////////
//Normal fenwick tree operations;
////////////
// keep in mind that 0&-0 = 0; so do not put start with 0 as a index otherwise it will
// stuck in infinite loop;

const int maxn=1e5+5;
vector<int> bit(maxn,0);

void update(int i,int val)
{
    i++;
    while(i<maxn){
        bit[i]+=val;
        i+=i&-i;
    }
}

int query(int i)
{
    i++;
    int sum=0;
    while(i){
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}