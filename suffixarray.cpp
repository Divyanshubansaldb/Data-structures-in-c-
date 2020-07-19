typedef struct suffixarray
{
    string s;
    vector<int> p;
    vector<int> c;
    vector<int> lcp;
    int n;

    suffixarray() {}
    suffixarray(string s) : s(s)
    {
        s+='$';
        n=s.size();
        p.resize(n);
        c.resize(n);
        lcp.resize(n);
        suffixcode();
        lcpcomp();
    }

    void count_sort()
    {
        int n=p.size();
        vector<int> cnt(n);
        for (int i = 0; i < n; i++)
        {
            cnt[c[i]]++;
        }
        
        vector<int> pos(n);
        for (int i = 1; i < n; i++)
        {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        
        vector<int> p_new(n);

        for(int x: p)
        {
            p_new[pos[c[x]]]=x;
            pos[c[x]]++;
        }
        p=p_new;
    }

    void suffixcode()
    {
        {
            // for k==0;
            vector<pair<char,int>> a(n);
            for (int i = 0; i < n; i++)
            {
                a[i]={s[i],i};
            }
            sort(a.begin(),a.end());
            for (int i = 0; i < n; i++)  p[i]=a[i].second;
            c[p[0]]=0;
            for (int i = 1; i < n; i++)
            {
                if(a[i].first==a[i-1].first)
                {
                    c[p[i]]=c[p[i-1]];
                }
                else
                {
                    c[p[i]]=c[p[i-1]]+1;
                }
            }
        }

        int k=0;
        while((1<<k)<n)
        {
            for (int i = 0; i < n; i++)
            {
                p[i]=(p[i]-(1<<k)+n)%n;
            }

            count_sort();
            vector<int> c_new(n);

            c_new[p[0]]=0;
            for (int i = 1; i < n; i++)
            {
                pair<int,int> prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
                pair<int,int> cur={c[p[i]],c[(p[i]+(1<<k))%n]};
                if(prev==cur)
                {
                    c_new[p[i]]=c_new[p[i-1]];
                }
                else
                {
                    c_new[p[i]]=c_new[p[i-1]]+1;
                }
            }
            c=c_new;
            if(c[p[n-1]]==n-1) break;
            k++;
        }
    }

    void lcpcomp()
    {
        int k=0;
        for (int i = 0; i < n-1; i++)
        {
            int pi=c[i];
            int j=p[pi-1];
            while(s[i+k]==s[j+k]) k++;
            lcp[pi]=k;
            k=max(k-1,0);
        }
    }

}suffix;