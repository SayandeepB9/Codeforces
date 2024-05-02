#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 998244353
#define inf 1e9+1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define msi multiset<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5
using namespace std;

void solve()
{
    ll n,m;
    cin>>n>>m;
    string s[n];
    in(s,n);
    vi a;

    fr(i,0,n-2)
    {
        fr(j,0,m-1)
        {
            if(s[i][j]=='1')
            {
                s[i][j]='0';
                a.pb(i+1),a.pb(j+1);
                if(s[i][j+1]=='1')
                {
                    s[i][j+1]='0';
                    a.pb(i+1),a.pb(j+2);
                    s[i][j+1]='0';
                    if(s[i+1][j]=='1') s[i+1][j]='0',a.pb(i+2),a.pb(j+1);
                    else
                    {
                        a.pb(i+2),a.pb(j+2);
                        if(s[i+1][j+1]=='1') s[i+1][j+1]='0';
                        else s[i+1][j+1]='1';
                    }
                }
                else
                {
                    if(s[i+1][j]=='1') s[i+1][j]='0';
                    else s[i+1][j]='1';
                    a.pb(i+2),a.pb(j+1);
                    a.pb(i+2),a.pb(j+2);
                    if(s[i+1][j+1]=='1') s[i+1][j+1]='0';
                    else s[i+1][j+1]='1';
                }
            }
        }
        if(s[i][m-1]=='1')
        {
            s[i][m-1]='0';
            a.pb(i+1),a.pb(m);
            if(s[i+1][m-1]=='1') s[i+1][m-1]='0';
            else s[i+1][m-1]='1';
            a.pb(i+2),a.pb(m);
            a.pb(i+2),a.pb(m-1);
            if(s[i+1][m-2]=='1') s[i+1][m-2]='0';
            else s[i+1][m-2]='1';
        }
    }
    int k=0;
    fr(i,0,m-2)
    {
        int count=0;
        if(s[n-2][i]=='1') s[n-2][i]='0',a.pb(n-1),a.pb(i+1),count++;
        if(s[n-1][i]=='1') s[n-1][i]='0',a.pb(n),a.pb(i+1),count++;

        if(count==1)
        {
            if(s[n-2][i+1]=='1') s[n-2][i+1]='0';
            else s[n-2][i+1]='1';
            if(s[n-1][i+1]=='1') s[n-1][i+1]='0';
            else s[n-1][i+1]='1';
            a.pb(n-1),a.pb(i+2);
            a.pb(n),a.pb(i+2);
        }
        if(count==2)
        {
            if(s[n-1][i+1]=='1') s[n-1][i+1]='0',a.pb(n),a.pb(i+2);
            else
            {
                if(s[n-2][i+1]=='1') s[n-2][i+1]='0';
                else s[n-2][i+1]='1';
                a.pb(n-1),a.pb(i+2);
            }
        }
    }
    int flag=1;
    int tot=(s[n-1][m-1]=='1')+(s[n-2][m-1]=='1')+(s[n-1][m-2]=='1')+(s[n-2][m-2]=='1');
    switch(tot)
    {
        case 4:
            s[n-1][m-1]='0',a.pb(n),a.pb(m);
            s[n-1][m-2]='0',a.pb(n),a.pb(m-1);
            s[n-2][m-1]='0',a.pb(n-1),a.pb(m);
        case 1:
            if(s[n-1][m-1]=='1' || s[n-1][m-2]=='1')
            {
                if(s[n-1][m-1]=='1') s[n-1][m-1]='0',a.pb(n),a.pb(m);
                else s[n-1][m-2]='0',a.pb(n),a.pb(m-1);
                s[n-2][m-1]='1',a.pb(n-1),a.pb(m);
                s[n-2][m-2]='1',a.pb(n-1),a.pb(m-1);
            }
            else
            {
                if(s[n-2][m-1]=='1') s[n-2][m-1]='0',a.pb(n-1),a.pb(m);
                else s[n-2][m-2]='0',a.pb(n-1),a.pb(m-1);
                s[n-1][m-1]='1',a.pb(n),a.pb(m);
                s[n-1][m-2]='1',a.pb(n),a.pb(m-1);
            }
        case 2:
            if(s[n-1][m-1]=='0') s[n-1][m-1]='1',a.pb(n),a.pb(m);
            else s[n-1][m-1]='0',a.pb(n),a.pb(m),flag=0;
            if(s[n-1][m-2]=='0') s[n-1][m-2]='1',a.pb(n),a.pb(m-1);
            else if(flag) s[n-1][m-2]='0',a.pb(n),a.pb(m-1),flag=0;
            if(s[n-2][m-2]=='0') s[n-2][m-2]='1',a.pb(n-1),a.pb(m-1);
            else if(flag) s[n-2][m-2]='0',a.pb(n-1),a.pb(m-1),flag=0;
            if(s[n-2][m-1]=='0') s[n-2][m-1]='1',a.pb(n-1),a.pb(m);
            else if(flag) s[n-2][m-1]='0',a.pb(n-1),a.pb(m);
        case 3:
            if(s[n-1][m-1]=='1') s[n-1][m-1]='0',a.pb(n),a.pb(m);
            if(s[n-1][m-2]=='1') s[n-1][m-2]='0',a.pb(n),a.pb(m-1);
            if(s[n-2][m-2]=='1') s[n-2][m-2]='0',a.pb(n-1),a.pb(m-1);
            if(s[n-2][m-1]=='1') s[n-2][m-1]='0',a.pb(n-1),a.pb(m);
    }
    cout<<a.size()/6<<'\n';
    k=0;
    for(auto i: a)
    {
        cout<<i<<' ';
        k++;
        if(k==6) k=0,cout<<'\n';
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