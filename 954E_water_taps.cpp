#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define int ll
#define ld long double
#define mod 998244353
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

void solve()
{
    int n,T;
    cin>>n>>T;
    ld sum=0;
    
    mii a,b;
    int c[n],d[n];
    in(c,n);
    in(d,n);
    fr(i,0,n)
    {
        int x,t;
        x=c[i],t=d[i];
        if(t<T) b[T-t]+=x;
        if(t>T) a[t-T]+=x;
        if(t==T) sum+=x;
    }
    int sum1=0,sum2=0;
    for(auto i:a) sum1+=i.first*i.second;
    for(auto i:b) sum2+=i.first*i.second;

    if(sum1>sum2) swap(a,b),swap(sum1,sum2);
    for(auto i:a) sum+=i.second;
    for(auto i:b)
    {
        if(sum1<i.first*i.second)
        {
            sum+=(ld)sum1/(ld)i.first;
            break;
        }
        sum1-=i.first*i.second;
        sum+=i.second;
    }
    cout<<setprecision(10)<<sum<<'\n';
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