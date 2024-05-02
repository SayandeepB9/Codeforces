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

int dfs(vvi& a, int* w, int node)
{
    if(a[node].empty()) return w[node]=1;
    int sum=1;
    int t=node;
    for(auto i:a[node])
        sum+=dfs(a,w,i);
    return w[node]=sum;
}

void dfsc(vvi& a, int* w, int* cen, int node, vi& tem, int k)
{
    int flag=-1;
    for(auto i: a[node])
    {
        if(w[node]<2*w[i])
        {
            flag=i;
            continue;
        }
        vi t;
        dfsc(a,w,cen,i,t,0);
    }
    if(flag!=-1)
    {
        tem.pb(node);
        if(k<tem.size())
        {
            int z=tem[k];
            while(k<tem.size() && (w[node]*2-2<=w[z] || w[flag]*2<=w[z]))
            {
                k++;
                cen[z]=node;
                z=tem[k];
            }
        }
        dfsc(a,w,cen,flag,tem,k);
    }
    else
    {
        cen[node]=node;
        fr(i,k,tem.size()) cen[tem[i]]=node;
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;
    int p[n];
    p[0]=0;
    vvi child(n);
    fr(i,1,n)
    {
        cin>>p[i];
        p[i]--;
        child[p[i]].pb(i);
    }
    int w[n]={};
    w[0]=dfs(child,w,0);
    int cen[n];
    fr(i,0,n) cen[i]=-1;
    vi tem;
    dfsc(child, w, cen, 0, tem, 0);

    while(q--)
    {
        int x;
        cin>>x; 
        x--;
        cout<<cen[x]+1<<'\n';
    }
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
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}