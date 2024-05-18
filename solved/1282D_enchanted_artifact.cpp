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
    string s="";
    fr(i,0,300) s.pb('a');
    cout<<s<<endl;
    int x;
    cin>>x;
    if(x==0) return;
    if(x==300)
    {
        cout<<'b'<<endl;
        int t=0;
        cin>>t;
        if(t==0) return;
        fr(i,0,t+1) cout<<'b';
        cout<<endl;
        return;
    }
    s="";
    fr(i,0,300-x) s.pb('a');
    cout<<s<<endl;
    int y;
    cin>>y;
    if(y==0) return;
    int a=300-x;
    int b=y;
    int n=a+b;
    s="";
    fr(i,0,n) s.pb('a');
    fr(i,0,n)
    {
        s[i]='b';
        cout<<s<<endl;
        cin>>x;
        if(x==0) return;
        if(x>=b) s[i]='a';
        else b=x;
    }
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

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