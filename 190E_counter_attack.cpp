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
#define pi pair<int,int>
#define si set<int>
#define mii map<int,int>
#define pq priority_queue
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,m;
    cin>>n>>m;
    vvi a(n);

    fr(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y),a[y].pb(x);
    }

    si b;
    fr(i,0,n) b.insert(i);

    vvi c;
    vi f;
    si d,e;

    
    while(b.size() || d.size())
    {
        if(d.empty())
        {
            d.insert(*b.begin());
            b.erase(b.begin());
        }
        int k=*d.begin();
        f.pb(k);
        d.erase(d.begin());
        for(auto i: a[k])
        {
            if(b.find(i)!=b.end())
            {
                e.insert(i);
                b.erase(i);
            }
        }
        for(auto i:b) d.insert(i);
        b.clear();
        for(auto i:e) b.insert(i);
        e.clear();
        if(d.empty()) c.pb(f),f.clear();
    }
    cout<<c.size()<<'\n';
    for(auto i: c)
    {
        cout<<i.size()<<' ';
        for(auto j: i) cout<<j+1<<' ';
        cout<<'\n';
    }
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
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}