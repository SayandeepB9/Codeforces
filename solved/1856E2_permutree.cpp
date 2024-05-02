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
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
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

template<int len=1>
int calc(vi& b, int k)
{
    if(k>=len)
    {
        return calc<min((int)2000010,len*2)> (b,k);
    }

    int t=*max_element(b.begin(), b.end());
    if(t*2>=k) return t*(k-t);
    if(b.size()<4)
    {
        int ma=0;
        int j=(1<<(b.size()));
        fr(i,1,j-1)
        {
            int sum=0;
            fr(l,0,b.size()) if(((i>>l)&1)) sum+=b[l];
            ma=max(ma,sum*(k-sum));
        }
        return ma;
    }
    bitset<len> z;
    z.set(0);
    mii mp;
    for(auto i:b) mp[i]++;
    vi v1;
    for (auto x : mp){
        int f=x.first;
        int s=x.second;
        for (ll i=1;i<=s;i*=2){
            s-=i;
            v1.push_back(f*i);
        }
        if (s) v1.push_back(f*s);
    }
    for(auto i:v1) z|=(z<<i);
    int m=0;
    int j=k/2;
    int ma=0;
    while(j>=0 && !z.test(j)) j--;
    ma=max(ma,j*(k-j));
    j=k/2;
    while(j<=k && !z.test(j)) j++;
    ma=max(ma,j*(k-j));
    return ma;
}

pair<int, int> dfs(vvi& a, int i)
{
    if(a[i].empty()) return {1,0};
    int sum=0, child=0;
    vi b;
    for(auto j:a[i])
    {
        pair<int,int> x = dfs(a,j);
        child+=x.first;
        b.pb(x.first);
        sum+=x.second;
    }
    sum+=calc(b, child);
    return {child+1, sum};
}

void solve()
{
    int n;
    cin>>n;
    vvi a(n);
    fr(i,1,n)
    {
        int x;
        cin>>x;
        x--;
        a[x].pb(i);
    }
    cout<<dfs(a,0).second<<'\n';
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