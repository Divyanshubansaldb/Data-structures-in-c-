const int P1 = 29;
const int P2 = 31;
const int MOD = 1e9 + 7;
 
struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;
 
	Hashs() {}
 
	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--) 
		{
			hashs[i]=(1LL * hashs[i+1] * P + s[i] - 'a' + 1) % MOD;
			pows[n-i]=(1LL * pows[n-i-1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n-1] * P)%MOD;
	}
	int get_hash(int l, int r) 
	{
		int ans=hashs[l] + MOD - (1LL*hashs[r+1]*pows[r-l+1])%MOD;
		ans%=MOD;
		return ans;
	}
};
Hashs h1, h2;
h1 = Hashs(s, P1, MOD);
h2 = Hashs(s, P2, MOD);