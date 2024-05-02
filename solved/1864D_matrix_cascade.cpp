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
    int n;
    cin>>n;
    int lazy[n+5][n+5]={0},r[n+5][n+5]={0};
    bool a[n+5][n+5]={0};
    fr(i,0,n)
        fr(j,0,n)
        {
            char c;
            cin>>c;
            a[i+1][j+1]=(c=='1');
        }

    int count=0;
    fr(i,1,n+1)
    {
        lazy[i+1][0]=lazy[i][0];
        fr(j,1,n+1)
        {
            if((lazy[i][j]+lazy[i][j-1]+r[i][j]+a[i][j])&1)  count++,lazy[i+1][j-1]++,r[i+1][j+2]--;
            if(lazy[i][j]>0)    lazy[i+1][j-1]+=lazy[i][j];
            if(r[i][j]<0)    r[i+1][j+1]+=r[i][j];
            lazy[i][j]+=lazy[i][j-1]+r[i][j];
        }
    }
    cout<<count<<'\n';
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