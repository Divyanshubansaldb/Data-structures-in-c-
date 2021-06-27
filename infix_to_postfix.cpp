#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define LL_MAX LLONG_MAX
#define ULL_MAX ULLONG_MAX
#define ull unsigned long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb(x) push_back(x)
#define re() pop_back()
#define eb(x) emplace_back(x)
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define all(a) a.begin(),a.end()
#define msort(a) sort(a.begin(),a.end())
#define pii pair<int,int>
#define sz(x) int(x.size())
#define mk make_pair
#define endl '\n'
#define LOCAL
#ifdef LOCAL
    #define deb(x) cout<<#x<<" "<<x<<" ";
    #define debendl(x) cout<<#x<<" "<<x<<endl;
#else
    #define deb(...) 1
    #define debendl(...) 1
#endif


class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int price(char c){
        if(c=='(') return -1;
        else if(c=='^') return 3;
        else if(c=='/' || c=='*') return 2;
        else if(c=='+' || c=='-') return 1;
        else return 0;
    }

    string infixToPostfix(string s)
    {
        stack<char> st;
        string infix;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                while(1){
                    char c = st.top();
                    st.pop();
                    if(c=='(') break;
                    infix.push_back(c);
                }
            }
            else if(s[i]=='(') {
                st.push('(');
            }
            else if(price(s[i]) == 0){
                infix.push_back(s[i]);
            }
            else{
                while(st.size()>0 && price(s[i])<=price(st.top())){
                    infix.push_back(st.top());
                    st.pop();
                }

                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            infix.push_back(st.top());
            st.pop();
        }
        return infix;
    }
};

int main()
{
    string s; cin>>s;
    Solution S;
    cout<<S.infixToPostfix(s)<<endl;
}