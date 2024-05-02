#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define inf 1e9 + 1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n)                      \
    fr(ij, 0, n) cout << a[ij] << ' '; \
    cout << '\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int, int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void dfs(vvi &a, map<int, map<int, int>> &b, vi &c, int i)
{
    c[i] = 1;
    for (auto j : a[i])
    {
        if (c[j])
            continue;
        b[i][j] = 1;
        dfs(a, b, c, j);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi a(n);
    map<int, map<int, int>> b;
    vi c(n, 0);
    vector<pair<int, int>> d;

    fr(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
        b[x][y] = 0;
        b[y][x] = 0;
        d.pb({x, y});
    }
    dfs(a, b, c, 0);
    for (auto i : d)
    {
        if (b[i.first][i.second] || b[i.second][i.first])
            cout << '1';
        else cout<<'0';
    }
    cout<<'\n';
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

    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}