#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define mod1 1000000007
#define inf 1e9+1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(ij, 0, n) cout << a[ij] << ' '; cout<<'\n'
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
#define M 1005

using namespace std;
using namespace __gnu_pbds; 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int query(int x)
{
    cout<<"? "<<x+1<<'\n';
    fflush(stdout);
    char c;
    cin>>c;
    if(c=='>') return 1;
    else if(c=='<') return -1;
    else return 0;
}

int val;

void divi(int a[], vi& b, int l, int r, int mi, int ma)
{
    if(r-l<=1) return;
    vi c,d;
    c.pb(mi),d.pb(ma);
    int m=(r+l)/2;
    int k=m-val;
    if(val<m) while(k--) query(ma);
    else while(k++) query(mi);

    int eq=0;
    for(auto i: b)
    {
        if(i!=ma && i!=mi)
        {
            int x=query(i);
            if(x==1)
            {
                d.pb(i);
                query(mi);
            }
            else if(x==-1)
            {
                c.pb(i);
                query(ma);
            }
            else
            {
                eq=i;
                a[i]=m;
                c.pb(eq);
                d.pb(eq);
            }
        }
    }
    val=m;
    divi(a,c,l,m,mi,eq);
    divi(a,d,m,r,eq,ma);
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    vi b;
    int ma=0;

    int c[n]={};
    fr(i,0,n)
    {
        int x=query(i);
        while(x==1)
        {
            ma++;
            x=query(i);
        }
        if(x==-1) ma--;
        c[i]=ma;
    }
    int maxi=0;
    fr(i,0,n) if(c[i]>c[maxi]) maxi=i;
    a[maxi]=n;

    fr(i,0,n)
    {
        int x=query(i);
        while(x==-1)
        {
            ma++;
            x=query(i);
        }
        if(x==1) ma--;
        c[i]=ma;
    }
    int mini=0;
    fr(i,0,n) if(c[i]>c[mini]) mini=i;
    a[mini]=1;

    while(query(mini));
    val=1;

    fr(i,0,n) b.pb(i);
    divi(a,b,1,n,mini,maxi);
    cout<<"! ";
    out(a,n);
    fflush(stdout);
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

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