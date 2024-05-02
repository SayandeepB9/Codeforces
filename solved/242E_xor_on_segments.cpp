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
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX (ll)2e5
using namespace std;
#define f21 fr(i,0,21)

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

ll tree[2*MAX+10][21]={0}, lazy[2*MAX+10][21]={0};
ll a[MAX+10];

void build_tree(int l, int r, int pos)
{
    if(l==r)
    {
        f21  tree[pos][i]=(a[l]>>i & 1);
        return;
    }
    int m=(l+r)/2;
    build_tree(l,m,pos*2);
    build_tree(m+1,r,pos*2+1);
    f21 tree[pos][i]=tree[pos*2][i]+tree[pos*2+1][i];
}

void updlazy(int l, int r, int pos)
{
    f21 if(lazy[pos][i] & 1)    tree[pos][i]=(r-l+1)-tree[pos][i];
    if(l!=r)    f21  if(lazy[pos][i]!=0) lazy[pos*2][i]+=lazy[pos][i],lazy[pos*2+1][i]+=lazy[pos][i];
    f21 lazy[pos][i]=0;
}

void upd(int l, int r, int pos, int ql, int qr, int val)
{
    f21 if(lazy[pos][i]!=0) updlazy(l,r,pos);

    if(l>=ql & r<=qr)
    {
        f21 tree[pos][i]=(val>>i & 1)?(r-l+1)-tree[pos][i]:tree[pos][i];
        if(l!=r) f21 lazy[pos*2][i]+=(val>>i & 1),lazy[pos*2+1][i]+=(val>>i & 1);
        return;
    }
    else if(l>qr || r<ql)   return;
    int mid=(l+r)/2;
    upd(l,mid,pos*2,ql,qr,val);
    upd(mid+1,r,pos*2+1,ql,qr,val);
    f21 tree[pos][i]=tree[pos*2][i]+tree[pos*2+1][i];
}

ll query(int l, int r, int pos, int ql, int qr)
{
    f21 if(lazy[pos][i])    updlazy(l,r,pos);
    if(l>=ql && r<=qr)
    {
        ll sum=0;
        f21 sum+=tree[pos][i]*(1<<i);
        return sum;
    }
    else if(l>qr || r<ql)   return 0;

    int mid=(l+r)/2;
    return query(l,mid,pos*2,ql,qr)+query(mid+1,r,pos*2+1,ql,qr);
}

void solve()
{
    int n,m;
    cin>>n;
    in(a,n);
    build_tree(0,n-1,1);

    cin>>m;
    fr(i,0,m)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int ql,qr;
            cin>>ql>>qr;
            cout<<query(0,n-1,1,ql-1,qr-1)<<'\n';
        }
        else
        {
            int ql,qr,val;
            cin>>ql>>qr>>val;
            upd(0,n-1,1,ql-1,qr-1,val);
        }
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

    ll tc=1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}