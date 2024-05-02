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
#define inf 1e9+7
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
#define M 1005

using namespace std;
using namespace __gnu_pbds; 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int dp[110][10005];

int calc(int c[], int y, int i, int b[], int n, int d[])
{
    int x= d[i]-y;
    int k=max(x,(int)0);
    if(k>c[i]) return dp[i][k]=0;
    if(dp[i][y]!=-1) return dp[i][y];
    int sum=0;
    fr(j,k,c[i]+1)
    {
        if(i!=n-1) sum+=calc(c,y+j,i+1,b,n,d);
        else sum++;
        sum=sum%mod1;
    }
    // cout<<i<<' '<<y<<' '<<sum<<'\n';
    return dp[i][y]=sum;
}

void solve()
{
    int n;
    cin>>n;
    int c[n],b[n-1],d[n];
    in(c,n);
    in(b,n-1);
    
    // int s=0;
    // fr(i,0,n) s+=c[i];

    fr(i,0,110) fr(j,0,10005) dp[i][j]=-1;
    int q,x;
    cin>>q>>x;
    if(x>100)
    {
        cout<<0<<'\n';
        return;
    }
    d[0]=x;
    fr(i,1,n) d[i]=d[i-1]+b[i-1];
    fr(i,1,n) d[i]+=d[i-1];

    cout<<calc(c,0,0,b,n,d)<<'\n';
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