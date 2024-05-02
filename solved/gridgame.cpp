#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i];
#define out(a, n) fr(i, 0, n) cout << a[i]<<" "
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pair<int,int>>
#define vmii vector<map<int,int>>
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

void yn(bool f)
{
    if(f)    cout<<"YES"<<'\n';
    else        cout<<"NO"<<'\n';
}

bool dfs(vmii& a,int n,int m,vi& colour,int node)
{
    for(auto i:a[node])
    {
        if(colour[i.first]==-1)
        {
            colour[i.first]=colour[node]^i.second;
            if(dfs(a,n,m,colour,i.first))
                return 1;
        }
        else if(colour[i.first]!=colour[node]^i.second)
            return 1;
    }
    return 0;
}

int solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vmii a(n+m+1);
    vi colour(n+m+1,-1);

    int x1,y1,x2,y2;
    bool flag=0;
    fr(i,0,k)
    {
        cin>>x1>>y1>>x2>>y2;

        x1--,y1--,x2--,y2--;
        bool c=((x1+y1)==(x2+y2));
        if(x1>x2)   x1=x2;
        if(y1>y2)   y1=y2;

        if(a[x1].find(y1+n)!=a[x1].end()) flag=1;

        a[x1].insert({y1+n,!c});
        a[y1+n].insert({x1,!c});
    }
    if(flag)    {yn(0); return 0;}

    fr(i,0,n)
        if(colour[i]==-1)
        {
            colour[i]=0;
            if(dfs(a,n,m,colour,i))
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