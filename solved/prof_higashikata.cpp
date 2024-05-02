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
#define vvi vector<vi>
#define vvll vector<vll>
#define mii map<int,int>
#define mmii multimap<int,int>
#define si set<int>
#define msi multiset<int>
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

int solve()
{
    int n, m, q;
    cin>>n>>m>>q;

    string s;
    cin>>s;

    int count = 0;
    fr(i,0,n)   count+=(s[i]=='1');

    mii c;
    fr(i,0,n)   c.insert({i,0});
    vi a,b;
    si temp;

    fr(i,0,n)   temp.insert(i);
    
    fr(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        --x,--y;

        auto it = temp.lower_bound(x);
        auto it2=it;
        while(it!=temp.end() && *it<=y)
        {
            b.pb(*it);
            it++;
        }
        temp.erase(it2,it);
    }
    reverse(b.begin(),b.end());

    fr(i,0,n)   c[i]=0;

    // cout<<"A : ";
    // for(auto i: a)
    //     cout<<i<<' ';
    // cout<<"\nB : ";
    // for(auto i: b)
    //     cout<<i<<' ';
    // cout<<"\n";

    int x, swap=0, count1=count;
    while(count-- && !b.empty())
    {
        x=*--b.end();
        b.pop_back();
        a.pb(x);
        c[x]=1;
        if(s[x]=='0')    swap++;
    }
    // cout<<"swap : "<<swap<<'\n';

    int y;
    fr(i,0,q)
    {
        // cout<<"A : ";
        // for(auto i: a)
        //     cout<<i<<' ';
        // cout<<"\nB : ";
        // for(auto i: b)
        //     cout<<i<<' ';
        // cout<<"\nC : ";
        // fr(i,0,n)
        //     cout<<c[i]<<' ';
        // cout<<"\n\n";

        cin>>y;
        y--;
        if(s[y]=='0')
        {
            count1++;
            x=-1;
            if(c[y]==1 && b.empty())    swap--;

            if(!b.empty())
            {
                x=*--b.end();
                b.pop_back();
                a.pb(x);
                c[x]=1;
            }
            if(c[y]==0 && x!=y && s[x]=='0') swap++;
            if(c[y]==1 && s[x]=='1')    swap--;

            s[y]='1';
        }
        else
        {
            count1--;
            if(a.size()>count1)
            {
                x=*--a.end();
                a.pop_back();
                b.pb(x);
                c[x]=0;
                if(c[y]==1 && x!=y && s[x]=='1') swap++;
                if(c[y]==0 && s[x]=='0') swap--;
            }
            else
            {
                if(c[y]==1)    swap++;
            }
            s[y]='0';
        }
        cout<<swap<<'\n';
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

    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}