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
    int n,c;
    cin>>n>>c;
    vi a,b,d;
    fr(i,0,n)
    {
        int x;
        cin>>x;
        a.pb(x);
    }

    int sum=0,sum2=0,sum3=0;
    for(auto i:a)
    {
        if(i>2*c) break;
        if(i&1)
        {
            b.pb(i);
            int k=i-c;
            k=max((int)0,k);
            int l=min(c,i);
            sum2+=i/2-k+1;
            sum+=upper_bound(b.begin(),b.end(),l-k)-b.begin();
        }
        else
        {
            d.pb(i);
            int k=i-c;
            k=max((int)0,k);
            int l=min(c,i);
            sum2+=i/2-k+1;
            sum+=upper_bound(d.begin(),d.end(),l-k)-d.begin();
        }
    }
    for(auto i:a)
    {
        sum3+=max(c-i+1,(int)0);
    }
    cout<<(c+2)*(c+1)/2-(sum2+sum3-sum)<<'\n';
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