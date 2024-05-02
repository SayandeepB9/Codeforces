#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define int ll
#define ld long double
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
#define MAX 2e5
#define M 1005

using namespace std;
using namespace __gnu_pbds; 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void merge(vi& a, vi& b)
{
    for(auto i:b) a.pb(i);
    b.clear();
}

int n,k=0;

pair<int,int> dfs(int i, vi& p, int b[], vvi& a, int par)
{
    vi newp;
    if(a[i].size()==1 && i!=0)
    {
        p.pb(i);
        return {b[i],b[i]};
    }
    multimap<int, pair<int,vi>> c;
    for(auto j: a[i])
    {
        if(par==j) continue;
        pair<int,int> l=dfs(j,newp,b,a,i);
        if(l.first==-2) return {-2,-2};
        c.insert({l.first, {l.second, newp}});
        newp.clear(); 
    }
    int prev=-1;
    p.pb(i);
    int fi=-1,la;
    for(auto j:c)
    {
        if(fi==-1) fi=j.first;
        if((prev+1)!=j.first && prev!=-1) return {-2,-2};
        merge(p,j.second.second);
        prev=j.second.first;
        p.pb(i);
    }
    return {fi,prev};
}

void solve()
{
    cin>>n;
    vvi a(n);
    fr(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y),a[y].pb(x);
    }
    
    fr(i,0,n) k+=(i&&(a[i].size()==1));
    int o[k];
    in(o,k);
    int b[n];
    fr(i,0,n) b[i]=-1;
    fr(i,0,k) b[o[i]-1]=i;
    vi path;
    pair<int,int> ans=dfs(0,path,b,a,-1);
    if(ans.first==-2)
    {
        cout<<-1<<'\n';
        return;
    }
    for(auto i:path) cout<<i+1<<' ';
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