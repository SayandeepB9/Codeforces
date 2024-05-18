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
    int n,m,k;
    cin>>n>>m>>k;
    int kk=k;
    int a[n];
    in(a,n);
    map<int,si> b;
    fr(i,0,n) b[a[i]].insert(i);
    vi c;
    multiset<int> s;
    while(k>0)
    {
        k-=m;
        c.pb(*((b.begin()->second).begin()));
        s.insert(b.begin()->first);
        b.begin()->second.erase(b.begin()->second.begin());
        if(b.begin()->second.size()==0) b.erase(b.begin());
    }
    sort(c.begin(),c.end());
    int l=c.size();
    int sum=m*m*l*(l-1)/2;
    int z=m-kk%m;
    if(kk%m==0) z=0;
    fr(i,0,l) sum+=a[c[i]]*m;
    int mi=8000000000000000000;
    fr(i,0,l)
    {
        mi=min(mi,sum-z*(l-1-i)*m-z*(a[c[i]]+m*i));
    }
    cout<<mi<<'\n';
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