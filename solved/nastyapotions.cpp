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
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define mll multimap<ll,ll>
#define MAX 1e5
#define inf 1e18
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

// void yn(bool f)
// {
//     if(f)    cout<<"YES"<<'\n';
//     else        cout<<"NO"<<'\n';
// }

ll cost_f(vvi& a,ll i,ll* cost)
{
    if(a[i].empty())    return inf;

    ll cst=0;
    for(auto j:a[i])    cst+=cost[j];
    return cst;
}

void djikstra_like(mll& b, vvi& a, vvi& c, ll* cost, bool* visit,int n)
{
    pair<int,int> s;
    int count=0;
    while(b.size())
    {
        s=*b.begin();
        b.erase(b.begin());
        ll x=s.first,y=s.second;
        // if(visit[y])  continue;
        visit[y]=1;
        count++;

        if(count>=a[y].size())
        {
            ll cst=cost_f(a,y,cost);
            if(cost[y]>cst)
                cost[y]=cst;
        }

        for(auto node:c[y])
            if(cost[node]>cost[y] && count>=a[node].size() && visit[node])
            {
                b.insert({cost[node],node});
                visit[node]=0;
            }
    }
}

void solve()
{
    int n,k;
    cin>>n>>k;

    ll cost[n];
    in(cost,n);

    fr(i,0,k)
    {
        int x;
        cin>>x;
        cost[--x]=0;
    }

    vvi a(n),c(n);

    fr(i,0,n)
    {
        ll x;
        cin>>x;
        fr(j,0,x)
        {
            ll y;
            cin>>y;
            a[i].pb(--y);
            c[y].pb(i);
        }
    }

    bool visit[n]={0};
    mll b;
    fr(i,0,n)   b.insert({cost[i],i});
    djikstra_like(b,a,c,cost,visit,n);
    out(cost,n);
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

    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}