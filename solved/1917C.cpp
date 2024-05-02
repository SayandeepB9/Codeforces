#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,k,d;
    cin>>n>>k>>d;
    int a[n];
    in(a,n);
    int b[k];
    in(b,k);
    int c=0,ma=0;
    fr(i,0,n) a[i]-=(i+1),(a[i])?1:ma++;
    // out(a,n);
    // cout<<ma<<'\n';

    if(ma) ma+=(d-1)/2;
    else ma+=d/2;

    int i=1;
    while(1)
    {
        if(i>2*n || i>=d) break;
        fr(j,0,b[(i-1)%k]) a[j]++;
        fr(j,0,n) (a[j])?1:c++;
        if(c+(d-i-1)/2>ma) ma=c+(d-i-1)/2;
        c=0;
        i++;
        cout<<ma<<'\n';
    }
    cout<<ma<<'\n';
    cout<<'\n';
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