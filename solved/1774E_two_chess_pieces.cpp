#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define int ll
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

// void yn(bool f)
// {
//     if(f)    cout<<"Yes"<<'\n';
//     else        cout<<"No"<<'\n';
// }

// vi prime;
// void seive()
// {
//     int p[int(MAX)+5]={0};
//     p[0]=1,p[1]=1;
//     fr(i,2,int(MAX)+5)
//     {
//         if(p[i]==0)
//         {
//             prime.pb(i);
//             int j=2*i;
//             while(j<(int)MAX+5)
//             {
//                 p[j]=1;
//                 j+=i;
//             }
//         }
//     }
// }

// ll kadence(ll* a, ll n)
// {
//     ll max=a[0],sum=a[0];
//     fr(i,1,n)
//     {
//         if(sum<0)   sum=0;
//         sum+=a[i];

//         if(max<sum) max=sum;
//     }
//     return max;
// }

void dfs(vvi& a, vi& vis, int d[], int c[], int node)
{
    if(vis[node]) return;
    vis[node]=1;
    int max=0;
    for(auto i:a[node])
    {
        dfs(a, vis, d, c, i);
        max=max>d[i]?max:d[i];
    }
    if(max) d[node]=max+1;
    else if(c[node]==1) d[node]=1;
    else d[node]=0;
}

void dfsc(vvi& a, vi& vis, int d[], int* count, int node)
{
    if(vis[node]) return;
    vis[node]=1;
    for(auto i:a[node])
    {
        if(d[i]>0 && !vis[i]) *count+=2;
        dfsc(a, vis, d, count, i);
    }
}

void solve()
{
    int n,d;
    cin>>n>>d;
    vvi a(n);
    fr(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    vi vis(n,0);
    int c1[n]={0},c2[n]={0};
    int m1;
    cin>>m1;
    fr(i,0,m1)
    {
        int x;
        cin>>x;
        c1[--x]=1;
    }
    int m2;
    cin>>m2;
    fr(i,0,m2)
    {
        int x;
        cin>>x;
        c2[--x]=1;
    }

    int d1[n]={0},d2[n]={0};
    dfs(a, vis, d1, c1, 0);
    vis.assign(n,0);
    dfs(a, vis, d2, c2, 0);
    int count=0;
    fr(i,0,n)
    {
        d1[i]=(d1[i]>d2[i]-d)?d1[i]:d2[i]-d;
        d2[i]=(d2[i]>d1[i]-d)?d2[i]:d1[i]-d;
    }

    vis.assign(n,0);
    dfsc(a, vis, d1, &count, 0);
    vis.assign(n,0);
    dfsc(a, vis, d2, &count, 0);
    cout<<count<<'\n';
}

int32_t main()
{
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
}