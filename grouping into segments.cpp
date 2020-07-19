s1.lcp.eb(0);
vector<pii> pr;
pr.eb(mk(0, 0));
pii remain = {0, n};
for (int i = 0; i < s1.lcp.size(); i++)
{
    int last = i;
    while (pr.back().first > s1.lcp[i])
    {
        pii cur = pr.back();
        last = cur.second;
        pr.re();
        ll val = (ll)cur.first * (i - cur.second + 1);
        if (ans < val)
        {
            ans = max(ans, val);
            remain = {s1.p[cur.second], cur.first};
        }
    }

    if (s1.lcp[i] > pr.back().first)
    {
        pr.eb(mk(s1.lcp[i], last));
    }
}