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
#define bcnt __builtin_popcountll

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    k--;
    int a[n];;
    in(a,n);
    int  b[n];
    fr(i,0,n) b[i]=a[i];
    swap(b[0],b[k]);
    int l=-1;
    fr(i,0,n) if(a[i]>a[k]) {l=i; break;}
    if(l==-1) return cout<<n-1<<'\n',void();
    int ma=max((int)0,l-1);
    swap(a[k],a[l]);
    int t=(l!=0);
    fr(i,l+1,n)
    {
        t++;
        if(a[i]>a[l]) break;
    }
    if(l<k) ma=max(ma,t-1);
    cout<<ma<<'\n';
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