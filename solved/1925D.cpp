#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define MAX 2e5
#define M 1005

using namespace std;
using namespace __gnu_pbds; 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int bin(int a, int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    int c=bin(a,b/2);
    if(b%2) return a*c%mod1*c%mod1;
    else return c*c%mod1;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int sum=0;
    fr(i,0,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sum+=c;
    }
    int l=bin(m,mod1-2)%mod1;
    int t=n*(n-1)/2%mod1;
    int p=bin(t,mod1-2)*m%mod1;
    int p2=p*p%mod1;
    // cout<<p<<'\n';
    cout<<(k*p%mod1*sum%mod1+p2*k%mod1*(k-1)%mod1*bin(2,mod1-2)%mod1)%mod1*l%mod1<<'\n';
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