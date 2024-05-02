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
#define in(a, n) fr(index, 0, n) cin >> a[index]
#define out(a, n) fr(index, 0, n) cout << a[index] << ' '; cout<<'\n'
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

void initseg(int *a, int* b, int k, int pos)
{
    if(pos>=k)
    {
        b[pos]=a[pos-k];
        return;
    }
    initseg(a,b,k,2*pos);
    initseg(a,b,k,2*pos+1);
    b[pos]=b[2*pos+1]+b[2*pos];
}

void update(int* b, int pos, int val)
{
    pos--;
    while(pos>0)
    {
        b[pos]+=val;
        pos/=2;
    }
}

int findseg(int* b, int val, int pos, int k)
{
    if(pos>=k) return pos;
    if(b[2*pos]>=val) return findseg(b,val,2*pos,k);
    else return findseg(b,val-b[2*pos],2*pos+1,k);
}

int sum(int* b, int pos, int k)
{
    if(k==1) return b[1];
    pos--;
    int s=0;
    while((pos/2&(pos/2-1)))
    {
        if(pos&1) s+=b[pos/2];
        else s+=b[pos];
        pos=pos/2-1;
    }
    if(pos&1) s+=b[pos/2];
    else s+=b[pos];
    return s;
}

void solve()
{
    int n,k,q;
    cin>>n>>q;
    k=n;
    if(n&(n-1)) k=1<<((int)(log2(n)+1));
    int a[k]={};
    in(a,n);
    int b[2*k];
    initseg(a,b,k,1);
    // fr(i,0,n) cout<<sum(b,i+k+1,k)<<'\n';

    fr(i,0,q)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int y;
            cin>>y;
            if(sum(b,k+n,k)<y)
            {
                cout<<"NO\n";
                continue;
            }
            int z=findseg(b,y,1,k)-k;
            z++;

            if(sum(b,z+k,k)==y) cout<<"YES\n";
            else
            {
                int l=n-z;
                if(sum(b,n+k,k)-sum(b,z+k,k)<2*l) cout<<"YES\n";
                else if(sum(b,l+1+k,k)<2*(l+1)) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
        else
        {
            int pos,val;
            cin>>pos>>val;
            update(b,pos+k,val-b[pos+k-1]);
        }
    }
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