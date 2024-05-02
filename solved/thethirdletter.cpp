#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i];
#define out(a, n) fr(i, 0, n) cout << a[i];
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define mii map<int,int>
#define mmii multimap<int,int>
#define si set<int>
#define vpii vector<pair<int,int>>
#define vvpii vector <vpii>
#define msi multiset<int>
using namespace std;

// pair<ll,ll> modular_inverse(ll a, ll m)
// {
//     if(m==0)
//         return {1,0};

//     pair<ll,ll> x=modular_inverse(m,a%m);
//     ll b=x.first;
//     ll c=x.second;
//     return {c,b-a/m*c};
// }

// ll fact(ll x)
// {
//     ll s=1;
//     while(x)
//         s=(s*x--)%mod;
//     return s;
// }

// ll commod(ll n,ll r,ll* fac)
// {
//     ll a=fac[n];
//     ll b=bin_exp(fac[n],mod-2,mod);
//     ll c=bin_exp(fac[n],mod-2,mod);
//     return (a*b%mod)*c%mod;
// }

// ll bin_exp_rec(ll a,ll b,ll m)
// {
//     if(b==0)    return 1;
    
//     ll c=bin_exp(a,b/2,m);
//     if(b&1)     return (c*c%m)*a%m;
//     else        return c*c%m;
// }

// ll bin_exp(ll a,ll b)
// {
//     ll p=1;

//     while(b)
//     {
//         if(b&1) p=p*a%mod;
//         a=a*a%mod;
//         b>>=1;
//     }
//     return p;
// }

bool dfs(int n, vvpii& a, vb& visited, vll& pos, ll position)
{
    if(!visited[n])    pos[n]=position, visited[n]=1;
    else if(pos[n]!=position)   return 0;
    else return 1;

    for(auto& node: a[n])
        if(!dfs(node.first, a, visited, pos, pos[n]+node.second))
            return 0;
    return 1;
}

void yn(bool f)
{
    if(f)    cout<<"YES"<<'\n';
    else        cout<<"NO"<<'\n';
}

int solve()
{
    int n,m;
    cin>>n>>m;
    vvpii a(n);

    fr(i,0,m)
    {
        int x,y,d;
        cin>>x>>y>>d;
        if(x>y)    swap(x,y), d=-d;
        x--,y--;
        a[x].pb({y,d});
        a[y].pb({x,-d});
    }

    vb visited(n,0);
    vll pos(n,inf);

    fr(i,0,n)
    {
        if(!visited[i])
            if(!dfs(i,a,visited,pos,0))
            {
                yn(0);
                return 0;
            }
    }
    yn(1);
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

    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}