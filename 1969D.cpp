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
    int n,k,l=0;
    cin>>n>>k;
    int a[n],b[n];
    in(a,n);in(b,n);
    map<int,multiset<int>> c;
    fr(i,0,n) if(a[i]<b[i]) c[b[i]].insert(a[i]),l++;

    if(l<=k) return cout<<0<<'\n',void();
    multiset<int> d;
    int pr=0,bu=0,se=0;
    for(auto i:c) for(auto j:i.second) bu+=j;
    fr(i,0,k)
    {
        int t=*(prev(c.end())->second.begin());
        prev(c.end())->second.erase((prev(c.end())->second.begin()));
        if(prev(c.end())->second.size()==0) c.erase(prev(c.end()));
        d.insert(t);
    }
    for(auto i:c) se+=i.first*i.second.size();
    int pp=se-bu;
    pr=max(pr,pp);
    while(c.size() && k)
    {
        int t=*(prev(c.end())->second.begin());
        int tt=prev(c.end())->first;
        prev(c.end())->second.erase((prev(c.end())->second.begin()));
        if(prev(c.end())->second.size()==0) c.erase(prev(c.end()));
        int r=*prev(d.end());
        d.erase(prev(d.end()));
        d.insert(t);
        pp=pp+r-tt;
        pr=max(pr,pp);
    }
    cout<<pr<<'\n';
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