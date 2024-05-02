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

int ma=0;

int dfs(vvi& a, int i, int p, int m)
{
    int s=1;
    for(auto j: a[i])
    {
        if(p==j) continue;
        s+=dfs(a,j,i,m);
    }
    if(s>=m) ma++,s=0;
    // cout<<ma<<'\n';
    return s;
}

bool check(int n, int k, vvi& a, int m)
{
    ma=0;
    dfs(a,0,-1,m);
    return (ma>=k+1);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vvi a(n);
    fr(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    int l=0,r=n;
    while(l<r)
    {
        int m=(l+r)/2;
        int v=check(n,k,a,m);
        (v)?l=m+1:r=m;
    }
    cout<<max((int)0,l-1)<<'\n';
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