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
    vector<set<int>> a(n);
    si b,f;
    fr(i,0,n)   b.insert(i);
    int c[n];
    int cou=n;
    fr(i,0,n)
    {
        cin>>c[i];
        c[i]--;
        b.erase(c[i]);
        a[c[i]].insert(i);
        f.insert(c[i]);
    }
    for(auto i: b)
    {
        cou--;
        cout<<i+1<<' ';
        a[c[i]].erase(i);
    }
    ll cost[n];
    in(cost,n);
    map<int, ll> y;
    map<ll, set<int>> z;
    for(auto i: f)
    {
        ll sum=0;
        for(auto j:a[i])
            sum+=cost[j];
        z[sum].insert(i);
        y[i]=sum;
    }
    while(!y.empty() && cou--)
    {
        auto it=z.begin();
        ll k=*(it->second).begin();
        ll fir=it->first;
        cout<<k+1<<' ';
        y.erase(k);
        z[fir].erase(k);
        if(!z[fir].size())  z.erase(fir);
        ll fear=c[k];
        if(y.lower_bound(fear)!=y.end() && y.lower_bound(fear)->first==fear)
        {
            ll s=y[fear];
            y[fear]-=cost[k];
            z[s].erase(fear);
            if(z[s].empty())    z.erase(s);
            z[s-cost[k]].insert(fear);
        }
    }
    cout<<'\n';
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