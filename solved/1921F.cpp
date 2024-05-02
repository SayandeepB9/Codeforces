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

using namespace std;
using namespace __gnu_pbds; 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    in(a,n);
    int lim=sqrt(n);
    vvi d(lim+1, vector<int>(n)), e(lim+1, vector<int>(n));
    fr(i,0,lim)
    {
        fr(j,0,n)
        {
            if(j<=i) d[i][j]=a[j],e[i][j]=a[j];
            else d[i][j]=a[j]*(j/(i+1)+1)+d[i][j-i-1],e[i][j]=a[j]+e[i][j-i-1];
        }
    }
    fr(i,0,q)
    {
        int s,dd,k;
        cin>>s>>dd>>k;
        if(dd>lim)
        {
            int sum=0,count=1;
            while(count<=k) sum+=a[s-1+dd*(count-1)]*count, count++;
            cout<<sum<<' ';
        }
        else
        {
            if(s<=dd) {cout<<d[dd-1][dd*(k-1)+s-1]<<' ';}
            else cout<<d[dd-1][dd*(k-1)+s-1]-d[dd-1][s-1-dd]-(e[dd-1][dd*(k-1)+s-1]-e[dd-1][s-1-dd])*((s-1)/dd)<<' ';
        }
    }
    cout<<"\n";
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