#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define inf 1e9+1
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

void solve()
{
    int n;
    cin>>n;
    int m[n][n];
    fr(j,0,n) in(m[j],n);
    int a[n][30];
    int b[n];

    fr(i,0,n) fr(j,0,30) a[i][j]=-1;
    fr(i,0,n)
    {
        fr(j,0,n)
        {
            int t = m[i][j];
            // cout<<t<<'\n';
            if(i!=j)
            {
                fr(k,0,30)
                {
                    // cout<<"if\n";
                    // cout<<k<<'\n';
                    if(((t>>k)&1)==0)
                    {
                        // cout<<"if ";
                        if(a[i][k]==1 || a[j][k]==1)
                        {
                            cout<<"NO\n";
                            return;
                        }
                        a[i][k]=a[j][k]=0;
                    }
                    else
                    {
                        // cout<<"else ";
                        if(a[i][k]==0 && a[j][k]==0)
                        {
                            cout<<"NO\n";
                            return;
                        }
                        else if(a[i][k]==0) a[j][k]=1;
                        else if(a[j][k]==0) a[i][k]=1;
                    }
                }
            }
            // fr(k,0,30) cout<<a[i][k]<<' ';
            // cout<<'\n';
        }
        
        // cout<<'\n';
        b[i]=0;
        // fr(j,0,30) cout<<a[i][j]<<' ';
        // cout<<'\n';
        fr(j,0,30) if(a[i][j]==-1) a[i][j]=1;
        // fr(j,0,30) cout<<a[i][j]<<' ';
        // cout<<'\n';
        fr(k,0,30) b[i]+=a[i][k]*(1<<k);
    }
    cout<<"YES\n";
    out(b,n);
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