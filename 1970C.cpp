#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define mod1 1000000007
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

int bp(int a, int b)
{
    if(b==1) return a;
    int c=bp(a,b/2);
    if(b&1) return c*c%mod1*a%mod1;
    else return c*c%mod1;
}

vvi child;

int dfs(int i,int p,vvi &b, int dp[])
{
    vi a;
    for(auto x:b[i])
    {
        if(x==p) continue;
        int k=dfs(x,i,b,dp);
        if(k) child[i][1]++;
        else child[i][0]++;
        a.pb(k);
    }
    for(auto x:a) if(x==0) return dp[i]=1;
    return dp[i]=0;
}

void dfs2(int i,int p,vvi &b, int dp[])
{
    if(p>=0)
    {
        if(child[p][0]>!dp[i]) child[i][1]++;
        else child[i][0]++;
        if(child[i][0]>=1) dp[i]=1;
        else dp[i]=0;
    }
    for(auto x:b[i])
    {
        if(x==p) continue;
        dfs2(x,i,b,dp);
    }
}

void solve()
{
    int n,t;
    cin>>n>>t;
    mii a;
    vvi b(n);
    child.clear();
    child.resize(n);
    fr(i,0,n)
    {
        child[i].resize(2);
        child[i][0]=0,child[i][1]=0;
    }
    int dp[n]={};
    fr(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x]++;
        a[y]++;
        b[x].pb(y);
        b[y].pb(x);
    }
    vvi child(n);
    dfs(0,-1,b,dp);
    dfs2(0,-1,b,dp);
    fr(i,0,t)
    {
        int l;
        cin>>l;
        l--;
        if(dp[l]) cout<<"Ron\n";
        else cout<<"Hermione\n";
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