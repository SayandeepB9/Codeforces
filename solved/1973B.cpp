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

int pref[100005+1][22];

int check(int m, int n)
{
    int t=0;
    fr(i,0,22) if(pref[m][i]-pref[0][i]) t+=(1ll<<i);
    fr(j,m+1,n+1)
    {
        int k=0;
        fr(i,0,22) if(pref[j][i]-pref[j-m][i]) k+=(1ll<<i);
        if(k!=t) return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    in(a,n);
    int l=1, r=n;
    fr(i,0,22) pref[0][i]=0;
    fr(i,0,n) fr(j,0,22)
    {
        pref[i+1][j]=pref[i][j]+((a[i]>>j)&1);
    }

    while(l<r)
    {
        int m=(l+r)/2;
        if(check(m,n)) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
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