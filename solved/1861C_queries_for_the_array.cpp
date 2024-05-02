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
    string a;
    cin>>a;
    int count=0,l=a.length();
    fr(i,0,l)
    {
        if(a[i]=='+')   count++;
        if(a[i]=='-')   count--;
        if(count<0 || (a[i]=='0' & count<2))
        {
            cout<<"NO\n";
            return;
        }
    }
    vi b;
    fr(i,0,l)
    {
        if(a[i]=='+')
        {
            if(b.size()<1)  b.pb(1);
            else if(*--b.end()==-1)    b.pb(-1);
            else    b.pb(0);
        }
        if(a[i]=='-')
        {
            auto t=--b.end();
            if(*t==1)   *prev(t)=1;
            b.erase(t);
        }
        if(a[i]=='0')
        {
            if(*--b.end()==1 || b.size()<2)
            {
                cout<<"NO\n";
                return;
            }
            *--b.end()=-1;
        }
        if(a[i]=='1')
        {
            if(b.size()<2)  continue;
            if(*--b.end()==-1)
            {
                cout<<"NO\n";
                return;
            }
            *--b.end()=1;
        }
    }
    cout<<"YES\n";
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