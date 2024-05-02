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
#define vvi vector<vector<int>>
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

// ll fact(int x)
// {
//     ll s=1;
//     while(x)
//         s=(s*x--)%mod;
//     return s;
// }

// ll commod(int n,int r,int* fac)
// {
//     ll a=fac[n];
//     ll b=(modular_inverse(fac[n-r],mod).first+mod)%mod;
//     ll c=(modular_inverse(fac[r],mod).first+mod)%mod;
//     return (a*b%mod)*c%mod;
// }

// ll bin_exp(int a,int b,int m)
// {
//     if(b==0)    return 1;
    
//     ll c=bin_exp(a,b/2,m);
//     if(b&1)     return (c*c%m)*a%m;
//     else        return c*c%m;
// }

// ll po(ll a,ll b)
// {
//     if(b==0)    return 1;
    
//     ll c=po(a,b/2);
//     if(b&1)     return (c*c)*a;
//     else        return c*c;
// }

int solve()
{
    ll n;
    cin>>n;
    ll b=log2(n);
    ll r=1e9;

    bool flag=0;
    fr(i,2,b+1)
    {
        ll l=2;
        while(l<r-1)
        {
            ll k=(l+r)/2;
            ll p=pow(k,i);
            if(p>=n || p<0)  r=k;
            else            l=k; 
        }

        ll p=pow(l,i);
        ll s=0;
        // cout<<l<<' '<<r<<' '<<p<<'\n';
        while(s<n && p>0)
        {
            s+=p;
            p/=l;
        }
        if(s==n && p==0)
        {
            cout<<"YES"<<'\n';
            flag=1;
            break;
        }
    }
    if(!flag)
        cout<<"NO"<<'\n';
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