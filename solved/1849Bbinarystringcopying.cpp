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

void solve()
{
    ll n,m;
    cin>>n>>m;
    int a[n];
    fr(i,0,n)
    {
        char c;
        cin>>c;
        a[i]=(c=='1');
    }
    int p0=-1,p1=-1;
    int b[n][2];

    fr(i,0,n)
    {
        if(!a[i]) p0=i;
        if(a[n-1-i])    p1=n-1-i;
        b[i][0]=p0;
        b[n-1-i][1]=p1;
    }

    vector<set<int>> mm(n);
    bool flag=0;
    fr(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        x=b[x][1];
        y=b[y][0];
        if(y>x && y>0 && x>=0) mm[x].insert(y);
        else    flag=1;
    }

    int s=0;
    fr(i,0,n)
        s+=mm[i].size();
    cout<<s+flag<<'\n';
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