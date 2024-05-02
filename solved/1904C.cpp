#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
#define mod 998244353
#define inf 1e18+1
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

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    in(a,n);
    if(k>2)
    {
        cout<<0<<'\n';
        return;
    }
    if(k==0)
    {
        cout<<*min_element(a,a+n)<<'\n';
        return;
    }
    si b;
    fr(i,0,n) fr(j,i+1,n) b.insert(abs(a[i]-a[j]));
    int m=min(*b.begin(),*min_element(a,a+n));
    if(k==1)
    {
        cout<<m<<'\n';
        return;
    }
    fr(i,0,n)
    {
        auto t=b.lower_bound(a[i]);
        if(t!=b.end()) m=min(m,abs(*t-a[i]));
        if(t!=b.begin()) t--,m=min(m,abs(*t-a[i]));
    }
    cout<<m<<'\n';
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