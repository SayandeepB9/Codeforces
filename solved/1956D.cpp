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

vvi d;

void get_ans(int l, int r)
{
    if(l==r)
    {
        return;
    }
    get_ans(l,r-1);
    d.pb({l,r-1});
    if(l+1<=r-1) d.pb({l+1,r-1});
    get_ans(l+1,r);
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    in(a,n);
    int s=0;
    int m=0;
    int k=1<<n;
    fr(i,0,k)
    {
        int ss=0,t=i,l=0;
        vi b;
        fr(j,0,n)
        {
            if((t>>j)&1) l++;
            else b.pb(l),l=0,ss+=a[j];
        }
        b.pb(l);
        for(auto j:b) ss+=j*j;
        if(s<ss) s=ss,m=i;
    }

    d.clear();
    fr(j,0,n)
    {
        int l=j;
        if((m>>j)&1)
        {
            int r=j;
            while(r<n && ((m>>r)&1)) j++,r++;
            d.pb({l,r-1});
        }
    }
    vvi e;
    for(auto i:d) e.pb(i);
    d.clear();
    for(auto i:e)
    {
        int l=i[0],r=i[1];
        fr(j,l,r+1) if(a[j]!=0) d.pb({j,j});
        get_ans(l,r);
        d.pb({l,r});
    }
    cout<<s<<' '<<d.size()<<'\n';
    for(auto i:d) cout<<i[0]+1<<' '<<i[1]+1<<'\n';
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