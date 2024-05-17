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

// dp[i]=31^i, dp2[i]=1/31^i
int dp[200005],dp2[200005];
 
int bp(int a, int b)
{
    if(b==0) return 1;
    int c=bp(a,b/2);
    if(b&1) return c*c%mod*a%mod;
    else return c*c%mod;
}
 
void calc()
{
    dp[0]=1,dp2[0]=1;
    int t=bp(31,mod-2);
    fr(i,1,200005) dp[i]=dp[i-1]*31%mod,dp2[i]=dp2[i-1]*t%mod;
}

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    int p[n+1]={};
    p[0]=0;
    fr(i,1,n+1) p[i]=(p[i-1]+(s[i-1]-96)*dp[i])%mod;
    si se;
    fr(i,0,n) if(s[i]==s[0]) se.insert(i);
    mii m;
    fr(i,1,n+1)
    {
        int co=0,j=0;
        int tt=(p[j+i]-p[j]+mod)%mod;
        tt=tt*dp2[0]%mod;
        while(j+i<=n)
        {
            int t=(p[j+i]-p[j]+mod)%mod;
            t=t*dp2[j]%mod;
            if(t==tt)
            {
                co++;
                auto it=se.upper_bound(j+i-1);
                if(it!=se.end()) j=*it;
                else j=n+1;
            }
            else
            {
                se.erase(j);
                auto it=se.upper_bound(j);
                if(it!=se.end()) j=*it;
                else j=n+1;
            }
        }
        m[co]=i;
    }
    fr(i,l,r+1)
    {
        if(i==1) cout<<n<<' ';
        else if(m.lower_bound(i)!=m.end()) cout<<m.lower_bound(i)->second<<' ';
        else cout<<0<<' ';
    }
    cout<<'\n';
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
    calc();
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}