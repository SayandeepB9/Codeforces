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
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
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

ll bi(ll a,ll b)
{
    ll p=1;

    while(b)
    {
        if(b&1) p=p*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return p;
}

int a[64]={},b[64]={};
void comp()
{
    a[0]=1,b[0]=1;
    fr(i,1,64)
    {
        int x=((1<<(i))-1)%mod*((1<<(i))-1)%mod;
        b[i]=4*b[i-1]+x; b[i]%=mod;
        a[i]=2*a[i-1]+3*b[i-1]+x; a[i]%=mod;
    }
}

void solve()
{
    int n;
    cin>>n;
    int s=0,t=1;

    while(n&(n-1))
    {
        int z=((int)log2((long double)n));
        int x=((ll)1)<<z;
        s=(s+t*(bi(2,x)-1)%mod*(bi(2,n-x)-1)%mod+(2*t-1)*b[z]%mod+a[z])%mod;
        cout<<z<<' '<<x<<'\n';
        n-=x;
        t=2*t+1; t%=mod;
    }
    cout<<s<<'\n';
    int z=((int)log2((long double)n));
    s+=(t-1)*b[z]%mod+a[z];
    cout<<s<<'\n';
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
    comp();
    out(a,10);
    out(b,10);
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}