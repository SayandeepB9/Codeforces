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
    int a[n];
    in(a,n);
    stack<int> s,t;
    int b[n],c[n];
    fr(i,0,n) b[i]=-1,c[i]=-1;
    fr(i,0,n)
    {
        while(!s.empty() && a[s.top()]<=a[i]) b[s.top()]=i,s.pop();
        s.push(i);
    }
    rev(i,n-1,0)
    {
        while(!t.empty() && a[t.top()]<=a[i]) c[t.top()]=i,t.pop();
        t.push(i);
    }
    int p[n+1]={};
    fr(i,0,n) p[i+1]=p[i]+a[i];
    fr(i,0,n)
    {
        if(b[i]!=-1) if(p[b[i]]-p[i]>0) return cout<<"NO\n",void();
        if(c[i]!=-1) if(p[i+1]-p[c[i]+1]>0) return cout<<"NO\n",void();
    }
    return cout<<"YES\n",void();
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