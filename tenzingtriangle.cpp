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
#define vmii vector<map<int,int>>
# define MAX 1e5
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

ll xcost(vmii& x,ll x1,ll y1)
{
    auto l=x[x1].lower_bound(y1);
    ll cost = 0;
    while(l!=x[x1].end())
    {
        cost+=l->second;
        l++;
    }
    cout<<"Cost "<<cost<<' '<<x1<<' '<<y1<<'\n';
    return cost;
}

ll ycost(vmii& y,ll x1,ll y1)
{
    auto l=y[y1].lower_bound(x1);
    ll cost = 0;
    while(l!=y[y1].end())
    {
        cost+=l->second;
        l++;
    }
    return cost;
}

vmii z;
ll total_cost=0;

ll xsearch(vmii& x, vmii& y, ll a, ll k, ll x1, ll y1);

ll ysearch(vmii& x,vmii& y,ll a,ll k,ll x1,ll y1)
{
    ll y_cost=ycost(y,x1,y1);
    ll i=1;
    for(;i+x1+y1<k;i++)
    {
        if(y_cost>a*i)  y_cost+=ycost(x,x1,y1+i);
        else if(i!=1)
        {
            y_cost=xsearch(x,y,a,k,k+1-i,y1);
            y_cost+=xsearch(x,y,a,k,x1,y1+i);
            break;
        }
        else
        {
            y_cost=xsearch(x,y,a,k,x1,y1+i);
            break;
        }
    }
    if(x1+y1+i==k && y_cost>i*a)  total_cost+=i*a;
    return y_cost;
}

ll xsearch(vmii& x,vmii& y,ll a,ll k,ll x1,ll y1)
{
    cout<<"Points"<<x1<<' '<<y1<<'\n';
    ll x_cost=xcost(x,x1,y1);
    int i=1;
    for(;i+x1+y1<k;i++)
    {
        if(x_cost>a*i)  x_cost+=xcost(x,x1+i,y1);
        else if(i!=1)
        {
            x_cost=xsearch(x,y,a,k,x1,k+1-i);
            x_cost+=xsearch(x,y,a,k,x1+i,y1);
            break;
        }
        else
        {
            x_cost=xsearch(x,y,a,k,x1+i,y1);
            break;
        }
    }
    if(i+x1+y1==k && x_cost>i*a)  x_cost=ysearch(x,y,a,k,x1,y1);
    return x_cost;
}

void solve()
{
    ll n,k,a;
    cin>>n>>k>>a;
    vmii x(k),y(k);
    ll sum=0;
    fr(i,0,n)
    {
        int x1,y1,c;
        cin>>x1>>y1>>c;
        x[x1].insert({y1,c});
        y[y1].insert({x1,c});
        sum+=c;
    }
    fr(i,0,k)
    {
        cout<<i<<' ';
        for(auto j:x[i])
            cout<<j.first<<' '<<j.second<<' ';
        cout<<'\n';
    }
    ll cost = xsearch(x,y,a,k,0,0);

    cout<<sum+total_cost-cost<<'\n';
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

    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}