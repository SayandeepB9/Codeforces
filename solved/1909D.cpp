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

int gcd(int a, int b)
{
    if(!(a%b)) return b;
    else return gcd(b,a%b);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    in(a,n);
    int flag=1;
    fr(i,0,n-1) if(a[i]!=a[i+1]) {flag=0; break;}
    if(flag) {cout<<0<<'\n'; return;}
    int m=*min_element(a,a+n);
    int ma=*max_element(a,a+n);
    if(k>=m && k<=ma) {cout<<-1<<'\n'; return;}
    fr(i,0,n) a[i]=abs(a[i]-k);
    int g=a[0];
    fr(i,0,n) g=gcd(a[i],g);
    int sum=0;
    fr(i,0,n) sum+=a[i]/g-1;
    cout<<sum<<'\n';
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