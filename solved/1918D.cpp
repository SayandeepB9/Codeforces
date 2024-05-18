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
#define inf 1e18+1
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

int dp[100005];

int check(int a[], int m, int n)
{
    mii b;
    dp[0]=a[0];
    b[dp[0]]++;
    int s=0,j=0;
    fr(i,1,n+1)
    {
        s+=a[i-1];
        while(s>m)
        {
            s-=a[j];
            if(j!=0)
            {
                b[dp[j-1]]--;
                if(b[dp[j-1]]==0) b.erase(dp[j-1]);
            }
            j++;
        }
        if(j!=0) dp[i]=b.begin()->first+a[i];
        else dp[i]=a[i];
        b[dp[i]]++;
    }
    if(dp[n]>m) return 0;
    else return 1;
}

void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    in(a,n);
    a[n]=0;
    int l=0;
    int r=0;
    fr(i,0,n) r+=a[i];
    while(l<r)
    {
        int m=(l+r)/2;
        if(check(a,m,n)) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
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