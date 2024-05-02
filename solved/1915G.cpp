#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
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
#define MAX 2e5
#define M 105

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int vis[M][M];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> a(n);
    fr(i,0,m)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        a[x].pb({y,z});
        a[y].pb({x,z});
    }
    
    int s[n];
    in(s,n);
    int ma = *max_element(s,s+n);
    fr(i,0,n+3) fr(j,0,ma+3) vis[i][j]=0;

    map<int,map<int,vector<int>>> al;
    al[0][s[0]].pb(0);
    while(al.size())
    {
        auto it=al.begin();
        int w=it->first;
        auto it2=(it->second).begin();
        int i=it2->second[0];
        int mi=it2->first;
        
        if(it2->second.size()==1) it->second.erase(it2);
        else it2->second.erase(it2->second.begin());
        if(it->second.size()==0) al.erase(it);
        if(vis[i][mi]) continue;
        vis[i][mi]=1;

        if(i==n-1)
        {
            cout<<w<<'\n';
            break;
        }
        for(auto j:a[i])
        {
            al[w+j.second*mi][min(mi,s[j.first])].pb(j.first);
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