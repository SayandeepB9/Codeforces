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

int query(int a, int b, int c, int d)
{
    cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    fflush(stdout);
    char x;
    cin>>x;
    if(x=='>') return 1;
    else if(x=='<') return -1;
    else return 0;
}

void solve()
{
    int n;
    cin>>n;
    int a=0;
    fr(i,1,n)
    {
        int x=query(a,a,i,i);
        if(x==-1) a=i;
    }
    vi b;
    int c=(a==0);
    b.pb(c);
    fr(i,0,n)
    {
        int x=query(a,c,a,i);
        if(x==0) b.pb(i);
        if(x==-1) b.clear(),b.pb(i),c=i;
    }
    c=b[0];
    for(auto i:b)
    {
        int x=query(i,i,c,c);
        if(x==-1) c=i;
    }
    cout<<"! "<<a<<' '<<c<<'\n';
    fflush(stdout);
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

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