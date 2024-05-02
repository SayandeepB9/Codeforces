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

int query(int a, int b)
{
    cout<<"? "<<a<<' '<<b<<' '<<'\n';
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int w=query(1,1);
    int x=query(n,1);

    int y=(x+w-(n-1))/2+1;
    int q;
    if(w-y+2<=n && w-y+2>=1 && y>=1 && y<=m) q=query(w-y+2,y);
    else q=1;
    if(q==0)
    {
        cout<<"! "<<w-y+2<<' '<<y<<endl;
        return;
    }
    y=query(1,m);
    x=(y+w-(m-1))/2+1;
    cout<<"! "<<x<<' '<<w-x+2<<endl;
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