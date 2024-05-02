#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,k,y;
    cin>>n>>k>>y;
    int l=y;
    int a[k];
    in(a,k);
    sort(a,a+k);
    int sum=0;
    fr(i,0,k-1) if(a[i+1]-a[i]==2) sum++;
    if(a[0]+(n-a[k-1])==2) sum++;
    int b[n]={};
    fr(i,0,k) b[a[i]-1]=1;
    fr(i,a[0]-1,n+a[0]-1)
    {
        if(b[i%n])
        {
            if(!b[(i+1)%n]&&!b[(i+2)%n])
            {
                b[(i+2)%n]=1;
                y--;
            }
        }
        if(y==0) break;
    }
    int t=0;
    while(y--)
    {
        while(b[t]) t++;
        b[t]=1;
    }
    vi c;
    fr(i,0,n) if(b[i]) c.pb(i+1);
    fr(i,0,c.size()-1) if(c[i+1]-c[i]==2) sum++;
    if(c[0]+(n-c[c.size()-1])==2) sum++;
    cout<<min(k+l-2+sum,n-2)<<'\n';
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