///deimal to binary
string dectobin(int x)
{
    string s;
    for(int i=30;i>=0;i--)
    {
        if(((x>>i)&1)!=0)
        {
            s+="1";
        }
        else
        {
            s+="0";
        }
    }
    return s;
}

// knapsack algorithm by using bitmask in O(N.W/32)

bitset<MAX_W> can;
int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x); // or just: can |= (can << x);
	}
	puts(can[W] ? "YES" : "NO");

//for finding value of bitset can.to_ullong()