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

int n;
int x[1005], y[1005], r[1005];
int c[1005];
int vis[1005];
int l,m;
int fl;

void dfs(int i, vvi& a)
{
    vis[i]=1;
    for(auto j:a[i])
    {
        if(vis[j])
        {
            if(c[i]==c[j]) fl=0;
            continue;
        }
        if(c[i]==1) c[j]=0,m++;
        else c[j]=1,l++;
        dfs(j,a);
    }
}

void solve()
{
    cin>>n;
    fr(i,0,n) cin>>x[i]>>y[i]>>r[i];
    fr(i,0,n) c[i]=-1,vis[i]=0;
    vvi a(n);
    fr(i,0,n) fr(j,i+1,n)
    {
        if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==(r[i]+r[j])*(r[i]+r[j]))
        {
            a[i].pb(j);
            a[j].pb(i);
        }
    }

    fr(i,0,n)
    {
        l=0,m=0;
        if(vis[i]) continue;
        c[i]=1,l++;
        fl=1;
        dfs(i,a);
        if(fl && l!=m) return cout<<"YES\n", void();
    }
    cout<<"NO\n";
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