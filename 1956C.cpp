#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    int a[n][n];
    vvi d;
    int k = 0;
    int p = n - 1;
    int s = 0;
    while (p >= 0)
    {
        if (k & 1)
        {
            vi c;
            fr(j, 0, n) a[j][p] = j + 1;
            k++;
            c.pb(2), c.pb(p + 1);
            fr(i, 0, n) c.pb(i + 1);
            d.pb(c);
        }
        else
        {
            vi c;
            fr(j, 0, n) a[p][j] = j + 1;
            k++;
            c.pb(1), c.pb(p + 1);
            fr(i, 0, n) c.pb(i + 1);
            d.pb(c);
        }
        if(k&1) p--;
    }

    fr(i, 0, n) fr(j, 0, n) s += a[i][j];
    cout << s << ' ' << k << '\n';
    for (auto i : d)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    cout << '\n';
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