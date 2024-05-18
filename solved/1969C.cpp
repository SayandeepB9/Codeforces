#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define inf 1e9+1
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
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
int dp[100005][11];
int a[100005];

int calc(int i, int k)
{
    if(i>=n) return dp[i][k]=0;
    if(dp[i][k]!=-1) return dp[i][k];
    int m=inf,s=0;
    dp[i][k]=calc(i+1,k);
    fr(j,0,k+1)
    {
        if(i+j>=n) break;
        s+=a[i+j];
        m=min(m,a[i+j]);
        dp[i][k]=max(dp[i][k], s-m*(j+1)+calc(i+j+1,k-j));
    }
    return dp[i][k];
}

void solve()
{
    cin>>n>>k;
    in(a,n);
    fr(i,0,n+1) fr(j,0,11) dp[i][j]=-1;
    int s=0;
    fr(i,0,n) s+=a[i];
    cout<<s-calc(0,k)<<'\n';
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