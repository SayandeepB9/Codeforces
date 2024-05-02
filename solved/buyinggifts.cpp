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

int result(mmii& a, msi& a1, mmii& b, msi& b1, int max_min)
{
    auto l1 = a1.lower_bound(max_min);
    int min =mod;

    if(l1!=a1.begin())
    {
         auto l2 = b1.lower_bound(max_min);
         min = *l2-*--l1;
         ++l1;
    }

    while(l1!=a1.end())
    {
        auto l2 = b1.lower_bound(*l1);
        auto l2_cop = l2;

        if(l2!=b1.end() && abs(*l1-*l2)<min)
        {
            auto range_a = a.equal_range(*l1);
            auto range_b = b.equal_range(*l2);
            int dist_a = distance(range_a.first, range_a.second);
            int dist_b = distance(range_b.first, range_b.second);
            if(dist_a!=1 || dist_b!=1 || range_a.first->second!=range_b.first->second)
                min=abs(*l1-*l2);
            else if(l2!=--b1.end() && abs(*l1-*++l2)<min)
                min=abs(*l1-*l2);
        }

        l2=l2_cop;

        if(l2!=b1.begin())
        {
            --l2;
            if(abs(*l1-*l2)<min)
            {
                auto range_a = a.equal_range(*l1);
                auto range_b = b.equal_range(*l2);
                int dist_a = distance(range_a.first, range_a.second);
                int dist_b = distance(range_b.first, range_b.second);
                if(dist_a!=1 || dist_b!=1 || range_a.first->second!=range_b.first->second)
                    min=abs(*l1-*l2);
                else if(l2!=b1.begin() && abs(*l1-*--l2)<min)
                    min=abs(*l1-*l2);
            }
        }
        l1++;
    }
    return min;
}

int solve()
{
    int n;
    cin>>n;
    mmii a;
    msi a1;
    mmii b;
    msi b1;

    int max_min = 0, min;
    fr(i,0,n)
    {
        int x,y;
        cin>>x>>y;
        a1.insert(x);
        b1.insert(y);
        a.insert({x,i});
        b.insert({y,i});

        min = (x>y)?y:x;
        max_min = (max_min>min)?max_min:min;
    }

    auto l1 = a1.lower_bound(max_min);
    auto l2 = b1.lower_bound(max_min);
    int ans;

    if(distance(l1, a1.end())>distance(l2, b1.end()))
        ans = result(b, b1, a, a1, max_min);
    else    ans = result(a, a1, b, b1, max_min);

    cout<<ans<<'\n';
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