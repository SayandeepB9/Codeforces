#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define mod1 1000000007
#define INF 1e18+1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(ij, 0, n) cout << a[ij] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class LazySegmentTree {
private:
    vector<int> t;
    vector<pair<pii, int>> lazy;
    int n;
    
    int combine(int a, int b) {
        return a+b; // Change this according to your requirement
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }

    void calc(int& a, pii addend, int l, int r)
    {
        if(addend.second) a = a/addend.second*addend.first;
        else a -= addend.first*(r-l+1);
    }

    void calc_lazy(pair<pii, int>& lz, pii append)
    {
        if(append.second)
        {
            if(lz.first.first==0) lz.first.first=append.first, lz.first.second=append.second, lz.second=lz.second/append.second*append.first;
            else lz.first.first=append.first, lz.second=lz.second/append.second*append.first;
        }
        else lz.second+=append.first;
    }

    void push(int v, int l, int r) {  
        calc(t[v*2], lazy[v].first, l, (l+r)/2);
        calc(t[v*2], {lazy[v].second,0}, l, (l+r)/2);
        calc_lazy(lazy[v*2], lazy[v].first);
        calc_lazy(lazy[v*2], {lazy[v].second,0});
        calc(t[v*2+1], lazy[v].first, (l+r)/2+1, r);
        calc(t[v*2+1], {lazy[v].second,0}, (l+r)/2+1, r);
        calc_lazy(lazy[v*2+1], lazy[v].first);
        calc_lazy(lazy[v*2+1], {lazy[v].second,0});
        lazy[v]={{0,0},0};
    }

    void update(int v, int tl, int tr, int l, int r, pii addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            calc(t[v], addend, l, r);
            calc_lazy(lazy[v], addend);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && tr == r)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), 
                       query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

public:
    LazySegmentTree(vector<int>& a) {
        n = a.size();
        t.assign(4*n, 0);
        lazy.resize(4*n, {{0,0},0});
        build(a, 1, 0, n-1);
    }

    void update(int l, int r, pii addend) {
        update(1, 0, n-1, l, r, addend);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    int x[m], v[m];
    in(x,m);
    in(v,m);
    mii a;
    fr(i,0,m) a[x[i]]=v[i];
    vi b(n);
    fr(i,1,n+1)
    {
        auto it=a.lower_bound(i);
        if(i==it->first) b[i-1]=0;
        else b[i-1]=(it->first-i)*((--it)->second);
    }

    LazySegmentTree tree(b);

    fr(i,0,q)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int y,z;
            cin>>y>>z;
            a[y]=z;
            auto it=a.lower_bound(y);
            int l=prev(it)->first;
            int r=next(it)->first;
            l--,r--;
            tree.update(l+1,y-1,{prev(it)->second*(r+1-y),0});
            tree.update(y,r,{z, prev(it)->second});
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<tree.query(l,r)<<'\n';
        }
    }
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc=1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}