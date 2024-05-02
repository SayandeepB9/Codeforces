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
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vi prime;
void seive()
{
    int p[MA]={0};
    p[0]=1,p[1]=1;
    fr(i,2,MA)
    {
        if(p[i]==0)
        {
            prime.pb(i);
            int j=2*i;
            while(j<MA)
            {
                p[j]=1;
                j+=i;
            }
        }
    }
}

void pf(int n, vi& a)
{
    for(auto i:prime)
    {
        if(n%i==0) a.pb(i);
        while(n%i==0) n/=i;
    }
    if(n!=1) a.pb(n);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    if(!(k&1)) k--;
    while(k>=1 && n>1)
    {
        vi a;
        pf(n,a);
        for(auto i:a) n=n-n/i;
        k-=2;
    }
    cout<<n<<'\n';
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
    seive();
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}