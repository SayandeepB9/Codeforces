#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 998244353
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
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    set<int> b;
    fr(i,0,n+10)    b.insert(i);
    int a[n];
    in(a,n);
    fr(i,0,n)   b.erase(a[i]);
    fr(i,0,n)
    {
        auto it=b.begin();
        b.insert(a[i]);
        a[i]=*it;
        b.erase(*it);
    }
    k--;
    int c=*b.begin();

    k%=(n+1);
    if(!k)    {out(a,n);}
    else
    {
        int i=n;
        k=(n+1-k)%n;
        while(i-->0)
        {
            if(k==n || !k)    cout<<c<<' ',i--;
            if(i>-1)    cout<<a[k++%n]<<' ';
        }
        cout<<'\n';
    }
}

int main()
{
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
}