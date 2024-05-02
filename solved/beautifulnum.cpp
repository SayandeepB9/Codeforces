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

long long modular_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

ll fact(int x)
{
    ll s=1;
    while(x)
        s=(s*x--)%mod;
    return s;
}

ll commod(int n,int r,int* fac)
{
    ll a=fac[n];
    ll b=modular_inverse(fac[n-r],mod);
    ll c=modular_inverse(fac[r],mod);
    return (a*b%mod)*c%mod;
}

bool good(ll n,ll a,ll b)
{
    while(n)
    {
        if(n%10!=a && n%10!=b)
            return false;
        n/=10;
    }
    return true;
}

int solve()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll s=0;
    ll c=b-a;
    ll sum=n*a-c;

    int fac[n];
    fac[0]=1;
    fr(i,1,n+1) fac[i]=fac[i-1]*1LL*i%mod;

    fr(i,0,n+1)
    {
        sum+=c;
        if(good(sum,a,b))
            s=(s+commod(n,i,fac))%mod;
    }
    cout<<s<<'\n';
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

    solve();
    // ll tc;
    // cin >> tc;
    // while (tc--)
    // {
    //     solve();
    // }
}