#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
#define mod (ll)1e9+7
#define mod1 998244353
#define inf (ll)1e19
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define msi multiset<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5
using namespace std;

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

int min(int a, int b)
{
    return a<b?a:b;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int visit(int* visited, int n)
{
    if(n==visited[n]) return n;
    else return (visited[n]=visit(visited, visited[n]));
}

int dfs(int* a, vvi& b, int* len, int* val, int* visited, int node, int s_node)
{
    cout<<node<<' '<<s_node<<'\n';
    // out(visited,5);
    if(visited[node]==-1);
    else if(visit(visited,node)==s_node) return 0;
    else {visited[node]=s_node; return len[node];}
    cout<<node<<' '<<s_node<<'\n';

    int ma=0;
    int k=inf;
    visited[node]=s_node;
    for(auto i:b[node])
    {
        int x=dfs(a,b,len,val,visited,i,s_node)+1;
        if(x>ma)
        {
            ma=x;
            k=val[i]+a[node];
        }
        else if(x==ma)
        {
            k=min(k,val[i]+a[node]);
        }
    }
    if(b[node].empty())
    {
        k=a[node];
        ma=1;
    }
    val[node]=k;
    visited[node]=node;
    return (len[node]=ma);
}

void solve()
{
    //Unsolved
    int n,e;
    cin>>n>>e;
    int a[n];
    vvi b(n);
    in(a,n);
    fr(i,0,e)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        b[x].pb(y);
    }
    int visited[n]={};  
    int len[n]={};
    int val[n];
    fr(i,0,n) val[n]=0,visited[i]=-1;
    int m=0;
    fr(i,0,n)
    {
        int t=0;
        if(visited[i]==-1) t=dfs(a,b,len,val,visited,i,i);
        m=max(m,t);
    }
    out(visited,n);
    out(len,n);

    int mi=inf;
    fr(i,0,n)
    {
        if(len[i]==m) mi=min(val[i],mi);
    }
    cout<<m<<' '<<mi<<'\n';
}

int32_t main()
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