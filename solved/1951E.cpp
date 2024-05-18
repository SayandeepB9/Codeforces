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
#define bcnt __builtin_popcountll

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int dp[1000005],dp2[1000005];

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
    fr(i,1,1000005) dp[i]=dp[i-1]*31%mod,dp2[i]=dp2[i-1]*t%mod;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int t=n;
    int f=0;
    fr(i,0,n/2) if(s[i]!=s[n-1-i]) {f=1; break;}
    if(f) return cout<<"YES\n"<<1<<"\n"<<s<<'\n',void();
    fr(i,0,n) if(s[0]!=s[i]) {t=i; break;}
    if(t==n) return cout<<"NO\n",void();
    int p[n]={},rr[n]={};
    p[0]=s[0]-97;
    fr(i,1,n) p[i]=(p[i-1]+(s[i]-97)*dp[i])%mod;
    rr[n-1]=s[n-1]-97;
    fr(i,1,n) rr[n-i-1]=(rr[n-i]+(s[n-i-1]-97)*dp[i])%mod;
    fr(i,0,n-1)
    {
        int k=p[i];
        int j=rr[0];
        if(i!=n-2) j-=rr[i+1];
        j=(j+mod)%mod;
        j=j*dp2[n-i-1]%mod;
        int kk=p[n-1];
        kk-=p[i];
        kk=(kk+mod)%mod;
        kk=kk*dp2[i+1]%mod;
        int jj=rr[i+1];
        if(jj!=kk && j!=k)
        {
            cout<<"YES\n"<<2<<'\n';
            fr(j,0,i+1) cout<<s[j];
            cout<<' ';
            fr(j,i+1,n) cout<<s[j];
            cout<<'\n';
            return;
        }
    }
    cout<<"NO\n";
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

    calc();
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