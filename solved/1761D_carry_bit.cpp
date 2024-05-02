#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod1 998244353
#define mod 1000000007
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

ll bin[1000010];
ll bin_exp(ll a,ll b)
{
    ll p=1;

    while(b)
    {
        if(b&1) p=p*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return p;
}

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

void solve()
{
    ll n,k;
    cin>>n>>k;

    if(k==0)
    {
        cout<<bin_exp(3,n)<<'\n';
        return;
    }
    if(k==n)
    {
        cout<<(1<<(k-1))<<'\n';
        return;
    }

    bin[0]=1;
    ll comb=1,po2=bin_exp(3,k-1),po3=bin_exp(3,n-k-1),com=n-k,i=1,sum=0;
    while(k>=i && n-k-i>=0)
    {
        if(bin[n-k-i+1]==-1)    bin[n-k-i+1]=bin_exp(n-k-i+1,mod-2);
        sum+=comb*po2%mod*po3%mod*com%mod*(1+3*i*bin[n-k-i+1]%mod)%mod;
        po2=po2*bin[3]%mod;
        po3=po3*bin[3]%mod;
        if(bin[i]==-1)    bin[i]=bin_exp(i,mod-2);
        if(bin[i+1]==-1)    bin[i+1]=bin_exp(i+1,mod-2);
        comb=comb*(k-i)%mod*bin[i]%mod;
        com=com*(n-k-i)%mod*bin[i+1]%mod;
        i++;
    }
    if(n-k-i==-1 && k+1!=i)
    {
        sum+=comb*po2%mod;
    }
    cout<<sum%mod<<'\n';
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

    fr(i,0,1000010) bin[i]=-1;
    fr(i,0,1000) bin[i]=bin_exp(i, mod-2);

    ll tc=1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}