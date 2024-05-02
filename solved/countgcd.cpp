#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define mod2 998244353
#define MAX 200000
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

vi prime, fact;
void seive()
{
    int p[MAX+5]={0};
    p[0]=1,p[1]=1;
    fr(i,2,MAX+5)
    {
        if(p[i]==0)
        {
            prime.pb(i);
            int j=2*i;
            while(j<MAX+5)
            {
                p[j]=1;
                j+=i;
            }
        }
    }
}

void yn(bool f)
{
    if(f)    cout<<"YES"<<'\n';
    else        cout<<"NO"<<'\n';
}

ll count(vi a, ll m, ll n)
{
    ll val=0, p;
    ll pow_set_size = (1 << n);
    fr(counter,1,pow_set_size)
    {
        p = m;
        fr(j,0,n)   if (counter & (1 << j)) p /= a[j];

        if (__builtin_popcount(counter) & 1)    val += p;
        else    val -= p;
    } 
    return (m-val);
}

ll num(ll m, ll a, ll b)
{
    ll n=b/a;
    set<ll> c;
    ll i=0;
    while(fact[i])
    {
        while(!(n%fact[i]))
        {
            c.insert(fact[i]);
            n/=fact[i];
        }
        if(n<2) break;
        i++;
    }
    if(n!=1)    c.insert(n);
    n=m/a;
    vi d;
    for(auto i:c)   d.pb(i);
    return count(d,n,c.size());
}

void factor(ll a)
{
    set<ll> c;
    ll i=0;
    while(prime[i])
    {
        while(!(a%prime[i]))
        {
            c.insert(prime[i]);
            a/=prime[i];
        }
        if(a<2) break;
        i++;
    }
    if(a!=1)    c.insert(a);
    for(auto i:c)   fact.pb(i);
}

int solve()
{
    ll n,m;
    cin>>n>>m;
    
    ll a[n];
    in(a,n);
    fr(i,0,n-1) if(a[i+1]==0 || a[i]<a[i+1] || a[i]%a[i+1]) {cout<<0<<"\n\n";return 0;}

    ll count=1;
    factor(a[0]);
    fr(i,1,n)
    {
        if(a[i]==a[i-1])    count=count*(m/a[i])%mod2;
        else    count=count*num(m,a[i],a[i-1])%mod2;
    }
    cout<<count<<"\n\n";
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

    seive();
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}