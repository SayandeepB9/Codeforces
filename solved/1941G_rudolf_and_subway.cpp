#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
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

int dfs(vector<vector<pair<int,int>>>& a, map<int,map<int,vi>>& f, vector<si>& col, int e, int i, int c, int w, multimap<int,pair<int,int>>& d, int visit[])
{
    if(visit[i]==1 && (col[i].find(c)!=col[i].end())) return -1;
    if(visit[i]==1)
    {
        col[i].insert(c);
        int val=-1;
        if(i==e) return w;
        for(auto j:f[i][c])
        {
            val=dfs(a,f,col,e,j,c,w,d,visit);
            if(val>=0) return val;
        }
        return val;
    }
    col[i].insert(c);
    visit[i]=1;
    int val=-1;
    if(i==e) return w;
    for(auto j:a[i])
    {
        if(j.second==c) val=dfs(a,f,col,e,j.first,c,w,d,visit);
        else d.insert({w+1,{j.first,j.second}});
        if(val>=0) return val;
    }
    return val;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> a(n);
    map<int,map<int,vi>> f;
    fr(i,0,m)
    {
        int x,y,c;
        cin>>x>>y>>c;
        x--,y--;
        a[x].pb({y,c});
        a[y].pb({x,c});
        f[x][c].pb(y);
        f[y][c].pb(x);
    }
    int b,e;
    cin>>b>>e;
    if(b==e) return cout<<0<<'\n', void();
    b--,e--;
    int visit[n]={};
    multimap<int,pair<int,int>> d;
    d.insert({0,{b,-1}});
    vector<si> col(n);
    while(d.size())
    {
        auto it=*d.begin();
        d.erase(d.begin());
        int ans=dfs(a,f,col,e,it.second.first,it.second.second,it.first,d,visit);
        if(ans>=0)
        {
            cout<<ans<<'\n';
            return;
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
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}