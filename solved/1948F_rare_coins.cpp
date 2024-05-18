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

int bp(int a, int b)
{
    if(!b) return 1;
    int c=bp(a,b/2);
    if(b&1) return c*c%mod*a%mod;
    else return c*c%mod;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    int a[n],b[n];
    in(a,n);in(b,n);
    int pa[n+1],pb[n+1];
    pa[0]=0,pb[0]=0;
    fr(i,0,n) pa[i+1]=pa[i]+a[i],pb[i+1]=pb[i]+b[i];

    int y=pb[n];
    int c[y+1];
    c[0]=1;
    fr(i,0,y) c[i+1]=c[i]*(y-i)%mod*bp(i+1,mod-2)%mod;

    int d[y+2];
    d[0]=0;
    fr(i,0,y+1) d[i+1]=d[i]+c[i];
    int po=bp(bp(2,y),mod-2);

    fr(i,0,q)
    {
        int l,r;
        cin>>l>>r;
        int w=pa[n]-2*(pa[r]-pa[l-1]);
        int x=y-(pb[r]-pb[l-1]);
        if(w+x<0) cout<<d[y+1]*po%mod<<'\n';
        else if(w+x>=y) cout<<0<<'\n';
        else cout<<(d[y+1]-d[w+x+1]+mod)*po%mod<<'\n';
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