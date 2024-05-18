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

int cal(int a, int b)
{
    if(b==0) return 0;
    int n=a/b;
    int t=a%b;
    int c=b-t;
    int d=(n+1)*(n+1)*t*(t-1)/2;
    int e=n*n*c*(c-1)/2;
    int f=n*(n+1)*c*t;
    return d+e+f;
}

int check(int c[], int n, int k, int b, int x)
{
    int sum=0;
    fr(i,0,n)
    {
        sum+=cal(c[i],k);
    }
    return b*sum-(k-1)*x;
}

void solve()
{
    int n,b,x;
    cin>>n>>b>>x;
    int c[n];
    in(c,n);

    int l=1,r=*max_element(c,c+n);
    while(l<r)
    {
        int m=(l+r)/2;
        int e=check(c,n,m,b,x);
        int f=check(c,n,m+1,b,x);
        if(e>f) r=m;
        else l=m+1;
        // cout<<m<<' '<<e<<' '<<f<<'\n';
    }
    cout<<check(c,n,r,b,x)<<'\n';
    // cout<<'\n';
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