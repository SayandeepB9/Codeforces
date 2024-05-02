#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define inf 1e18 + 1
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

int n, m;
int dp[55][55][55][55], g[55][55], d[55][55];

void precompute_2d_sum() {
    // Initialize a 4D vector to store precomputed sums
    // Precompute sums for each position (i, j)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = g[i - 1][j - 1] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }
}

int get_sum(int i, int j, int k, int l) {
    return d[k][l] - d[k][j - 1] - d[i - 1][l] + d[i - 1][j - 1];
}

int calc(int i, int j, int k, int l)
{
    if (i == k && l == j)
        return 0;
    if (dp[i][j][k][l] != inf)
        return dp[i][j][k][l];
    dp[i][j][k][l] = 0;
    dp[i][j][k][l] = get_sum(i+1,j+1,k+1,l+1);
    int t = inf;
    fr(x, i, k) t = min(calc(i, j, x, l) + calc(x + 1, j, k, l), t);
    fr(x, j, l) t = min(calc(i, j, k, x) + calc(i, x + 1, k, l), t);
    return dp[i][j][k][l] += t;
}

void solve()
{
    cin >> n >> m;
    fr(i, 0, n) fr(j, 0, m) cin >> g[i][j];
    precompute_2d_sum();

    fr(i, 0, n + 2) fr(j, 0, m + 2) fr(k, 0, n + 2) fr(l, 0, m + 2) dp[i][j][k][l] = inf;
    cout << calc(0, 0, n - 1, m - 1);
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
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}