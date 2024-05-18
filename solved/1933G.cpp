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

int getv(int x, int y)
{
    x%=4;
    y%=4;
    return 4*x+y;
}

void solve()
{
    int a[]={1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1};
    int b[]={1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0};
    int c[]={1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1};
    int d[]={1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0};

    vvi l(4, vi(16));
    fr(i,0,16) l[0][i]=a[i];
    fr(i,0,16) l[1][i]=b[i];
    fr(i,0,16) l[2][i]=c[i];
    fr(i,0,16) l[3][i]=d[i];
    int n,m,q;
    cin>>n>>m>>q;
    cout<<8<<'\n';
    cout<<4<<'\n';
    int x,y;
    string s,r;
    vector<map<string,int>> v(4);

    vi z;
    z.pb(0),z.pb(1),z.pb(2),z.pb(3);
    cin>>x>>y>>s;
    int t=getv(x,y);
    if(s=="square") r="circle";
    else r="square";
    fr(i,0,4)
    {
        auto& v1 = l[i];
        auto& m1 = v[i];
        m1[s]=v1[t];
        m1[r]=(1+v1[t])%2;
    }
    si lk;
    fr(i,1,q)
    {
        cin>>x>>y>>s;
        for(auto i:z)
        {
            t=getv(x,y);
            if(v[i][s]!=l[i][t]) lk.insert(i);
        }
        cout<<4-lk.size()<<'\n';
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