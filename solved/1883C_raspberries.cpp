#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 998244353
#define mod1 1000000007
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
#define MAX 2e3
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

int min(int a,int b)
{
    return a<b?a:b;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    in(a,n);
    int flag=0;
    int s[4]={0};
    switch(k)
    {
        case 2:
            fr(i,0,n) if(a[i]%2==0)
                        {
                            flag=1;
                            break;
                        }
            if(flag) cout<<0;
            else cout<<1;
            break;
        case 3:
            flag=3;
            fr(i,0,n) if(a[i]%3==0)
                        {
                            flag=0;
                            break;
                        }
                      else flag=min(flag,3-a[i]%3);
            cout<<flag;
            break;
        case 4:
            fr(i,0,n) s[a[i]%4]++;
            if(s[0]>0 || s[2]>1) cout<<0;
            else if(s[3]>0 || s[2]>0) cout<<1;
            else cout<<2;
            break;
        case 5:
            flag=5;
            fr(i,0,n) if(a[i]%5==0)
                        {
                            flag=0;
                            break;
                        }
                      else flag=min(flag,5-a[i]%5);
            cout<<flag;
    }
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

    ll tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}