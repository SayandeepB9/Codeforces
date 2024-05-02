#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
#define mod 998244353
#define inf 1e18+1
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
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


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

void create(int* z, int* b, int c, int n, int k)
{
    if(k>=c/2)
    {
        if(k>=c/2+n) z[k]=inf;
        else z[k]=b[k-c/2];
        return;
    }
    create(z,b,c,n,2*k);
    create(z,b,c,n,2*k+1);
    z[k]=min(z[2*k],z[2*k+1]);
}

int fin(int* x, int l, int r, int a, int b, int t)
{
    if(l==a && r==b) return x[t];
    int m=(a+b)/2;
    if(l>m) return fin(x,l,r,m+1,b,2*t+1);
    else if(r<=m) return fin(x,l,r,a,m,2*t);
    else return min(fin(x,l,m,a,m,2*t),fin(x,m+1,r,m+1,b,2*t+1));
}

void createa(int* z, int* b, int c, int n, int k)
{
    if(k>=c/2)
    {
        if(k>=c/2+n) z[k]=0;
        else z[k]=b[k-c/2];
        return;
    }
    createa(z,b,c,n,2*k);
    createa(z,b,c,n,2*k+1);
    z[k]=max(z[2*k],z[2*k+1]);
}

int fina(int* x, int l, int r, int a, int b, int t)
{
    if(l==a && r==b) return x[t];
    int m=(a+b)/2;
    if(l>m) return fina(x,l,r,m+1,b,2*t+1);
    else if(r<=m) return fina(x,l,r,a,m,2*t);
    else return max(fina(x,l,m,a,m,2*t),fina(x,m+1,r,m+1,b,2*t+1));
}

void solve()
{
    int n;
    cin>>n;
    int a[n],b[n];
    in(a,n);
    in(b,n);
    map<int,si> x;
    fr(i,0,n) x[a[i]].insert(i);
    int c=log2(n-1)+1;
    c=1<<(c+1);
    int z[2*c]={};
    int az[2*c]={};
    createa(az,a,c,n,1);
    create(z,b,c,n,1);
    // out(az,c);

    fr(i,0,n)
    {
        if(a[i]!=b[i])
        {
            if(a[i]>b[i])
            {
                cout<<"NO\n";
                return;
            }
            else
            {
                if(x[b[i]].empty())
                {
                    cout<<"NO\n";
                    return;
                }
                else
                {
                    auto k=x[b[i]].lower_bound(i);
                    if(k!=x[b[i]].end())
                    {
                        int t=fina(az,i+1,*k,0,c/2-1,1);
                        int m=fin(z,i+1,*k,0,c/2-1,1);
                        // cout<<i<<' '<<t<<' '<<m<<' '<<*k<<'\n';
                        if(m>=b[i] && t<=b[i]) continue;
                    }
                    if(k!=x[b[i]].begin())
                    {
                        --k;
                        int t=fina(az,*k,i-1,0,c/2-1,1);
                        int m=fin(z,*k,i-1,0,c/2-1,1);
                        // cout<<i<<' '<<t<<' '<<m<<' '<<*k<<'\n';
                        if(m>=b[i] && t<=b[i]) continue;
                    }
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}