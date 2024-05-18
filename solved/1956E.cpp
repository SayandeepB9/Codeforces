#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi b;
    int c=1;
    fr(i,1,n)
    {
        if(s[i]==s[i-1]) c++;
        else ((c&1)?b.pb(1):b.pb(2)),c=1;
    }
    (c&1)?b.pb(1):b.pb(2);
    c=0;
    int ma=0,mi=0,cur=0,t=0;
    fr(i,0,b.size())
    {
        if(b[i]==1) t++;
        else
        {
            t++;
            if(c) cur+=t;
            else cur-=t;
            t=1;
            c^=1;
            ma=max(ma,cur);
            mi=min(mi,cur);
        }
    }
    if(c) cur+=t;
    else cur-=t;
    ma=max(ma,cur);
    mi=min(mi,cur);
    cout<<ma-mi<<'\n';
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