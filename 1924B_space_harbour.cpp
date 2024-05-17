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
    vector<vector<pii>> lazy;
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

    void calc(int& a, pii addend)
    {
        if(addend.second) a = a*addend.first/addend.second;
        else a -= addend.first;
    }

    void push(int v) {
        for(auto i: lazy[v])
        {    
            calc(t[v*2], i);
            lazy[v*2].pb(i);
            calc(t[v*2+1], i);
            lazy[v*2+1].pb(i);
        }
        lazy[v].clear();
    }

    void update(int v, int tl, int tr, int l, int r, pii addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            calc(t[v], addend);
            lazy[v].pb(addend);
        } else {
            push(v);
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
        push(v);
        int tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), 
                       query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

public:
    LazySegmentTree(vector<int>& a) {
        n = a.size();
        t.assign(4*n, 0);
        lazy.resize(4*n, {});
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
    int n;
    cin>>n;
    
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
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}