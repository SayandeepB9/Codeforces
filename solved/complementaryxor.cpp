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

void yn(bool f)
{
    if(f)    cout<<"YES"<<'\n';
    else        cout<<"NO"<<'\n';
}

int solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(n==1 && b[0]=='1')   {yn(0);return 0;}
    bool c=(a[0]==b[0]);
    fr(i,0,n)   if((a[i]==b[i])!=c) {yn(0);return 0;}

    yn(1);
    int count=0;
    fr(i,0,n)   count+=(a[i]=='1');
    if(c)
    {
        if(count & 1)   cout<<count+3<<'\n';
        else    cout<<count<<'\n';
    }
    else
    {
        if(count & 1)   cout<<count<<'\n';
        else    cout<<count+3<<'\n';
    }
    fr(i,0,n)   if(a[i]=='1')   cout<<i+1<<' '<<i+1<<'\n';
    if((c && (count & 1))||(!c && !(count & 1)))
    {
        cout<<1<<' '<<1<<'\n';
        cout<<1<<' '<<n<<'\n';
        cout<<2<<' '<<n<<'\n';
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

    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}