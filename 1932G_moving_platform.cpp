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
#define MAX 100005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int l[MAX],s[MAX],n,m,H,dp[MAX];
vvi a(MAX);

void dijk()
{
    unordered_map<int, unordered_map<int,int>> vis;
    multimap<int,int> q;
    q.insert({0,0});
    while(q.size())
    {
        pair<int,int> p=*q.begin();
        q.erase(q.begin());
        int k=p.first;
        int i=p.second;
        if(dp[i]==-1) dp[i]=k;
        dp[i]=min(dp[i],k);
        for(auto j: a[i])
        {
            if(vis[i][j]||vis[j][i]) continue;
            vis[i][j]=1,vis[j][i]=1;
            int li=(l[j]-l[i])+k*(s[j]-s[i]);
            // cout<<li<<' '<<(l[j]-l[i])<<'\n';
            li%=H;
            li=(li+H)%H;
            int sj=(s[j]-s[i])%H;
            if(sj>0) li=H-li;
            sj=abs(sj);
            int g=__gcd(sj,H);

            cout<<"i :"<<i<<' '<<j<<' '<<dp[i]<<'\n';
            cout<<H<<' '<<li<<' '<<g<<'\n';
            if((li)%g) continue;
            q.insert({(li)/sj+((li)%sj)/g+k,j});
        }
    }
}

void solve()
{
    cin>>n>>m>>H;
    fr(i,0,n) dp[i]=-1;
    fr(i,0,n) a[i].clear();
    in(l,n);
    in(s,n);
    out(l,n);
    out(s,n);
    fr(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    dijk();
    if(dp[n-1]==-1) cout<<dp[n-1]<<'\n';
    else cout<<dp[n-1]+1<<'\n';
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