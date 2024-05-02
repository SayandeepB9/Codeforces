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
#define bcnt __builtin_popcountll

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int ans=0,n,m,a[101][101];

mii dp[101][101];

int calc(int i, int j, int g)
{
    if(i==n-1 && j==m-1) return ans=max(ans,__gcd(g,a[n-1][m-1]));
    if(dp[i][j][g]) return dp[i][j][g];
    g=__gcd(g,a[i][j]);
    dp[i][j][g]=0;
    if(g>ans)
    {
        if(i!=n-1) dp[i][j][g]=max(dp[i][j][g],calc(i+1,j,g));
        if(j!=m-1) dp[i][j][g]=max(dp[i][j][g],calc(i,j+1,g));
    }
    return dp[i][j][g];
}

void solve()
{
    ans=0;
    cin>>n>>m;
    fr(j,0,n) in(a[j],m);
    fr(i,0,n+1) fr(j,0,m+1) dp[i][j].clear();
    calc(0,0,a[0][0]);
    cout<<ans<<"\n";
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