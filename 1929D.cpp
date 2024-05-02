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

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vi dfs(vvi& a, int i, int p)
{
    vi b,c,d;
    for(auto j:a[i])
    {
        if(j==p) continue;
        vi e=dfs(a,j,i);
        b.pb(e[0]);
        c.pb(e[1]);
        d.pb(e[2]);
    }
    if(b.empty()) return {1,1,0};
    int s1=1,s2=1,s3=0;
    for(auto k:b) s1=s1*k%mod;
    vi f;
    f.pb(s1);
    fr(k,0,b.size()) s2=s2*(b[k]+c[k])%mod;
    f.pb(s2);
    
    fr(k,0,d.size()) s3=(s3+d[k])%mod;
    fr(k,0,c.size()) s3=(s3+c[k])%mod;
    f.pb(s3);
    return f;
}

void solve()
{
    int n;
    cin>>n;
    vvi a(n);
    fr(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    vi ans=dfs(a,0,-1);
    cout<<(ans[0]+ans[1]+ans[2])%mod<<"\n";
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