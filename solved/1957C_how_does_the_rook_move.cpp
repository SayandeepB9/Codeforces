#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define mod1 1000000007
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
    if(b==1) return a;
    int c=bp(a,b/2);
    if(b&1) return c*c%mod1*a%mod1;
    else return c*c%mod1;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int s=0,t=0;
    fr(i,0,k)
    {
        int x,y;
        cin>>x>>y;
        s+=(x==y);
        t+=(x!=y);
    }
    n-=s+2*t;
    int a=1,sum=0,c=1;
    fr(i,0,n+1)
    {
        if(i!=0) c=c*(n-i+1)%mod1*(n-i+2)%mod1*bp(i,mod1-2)%mod1*bp(i-1,mod1-2)%mod1,a=a%mod1*(2*(i-1))%mod1;
        sum+=c*a%mod1;
        sum%=mod1;
        i++;
    }
    cout<<sum<<'\n';
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