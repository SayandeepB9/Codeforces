#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define inf 1e9 + 1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n)                      \
    fr(ij, 0, n) cout << a[ij] << ' '; \
    cout << '\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int, int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int bp(int a, int b)
{
    if(b==0) return 1;
    int c=bp(a,b/2);
    if(b&1) return c*c%mod*a%mod;
    else return c*c%mod;
}

int dp1[200005],dp2[200005];

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    mii a, b;
    fr(i, 0, n - 1) if (s[i] != s[i + 1]) a[i] = i + 1;
    fr(i, 0, n - 2) if (s[i] != s[i + 2]) b[i] = i + 2;
    int p[n]={},rr[n]={};
    p[0]=s[0]-97;
    fr(i,1,n) p[i]=(p[i-1]+(s[i]-97)*dp1[i])%mod;
    rr[n-1]=s[n-1]-97;
    fr(i,1,n) rr[n-i-1]=(rr[n-i]+(s[n-i-1]-97)*dp1[i])%mod;

    fr(i, 0, q)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0, flag = 0, f1 = 0, f2 = 0;
        if (a.lower_bound(l) != a.end() && a.lower_bound(l)->second <= r)
            f1 = 1, ans += (r - l + 1) / 2 * ((r - l + 1) / 2 + 1) / 2 * 2;
        if (b.lower_bound(l) != b.end() && b.lower_bound(l)->second <= r)
            f2 = 1, ans += (r - l + 2) / 2 * ((r - l + 2) / 2) - 1;
        if ((((r-l+1)&1) && f2) || (!((r-l+1)&1) && f1))
        {
            int k=p[r];
            if(l!=0) k-=p[l-1];
            k=(k+mod)%mod;
            k=k*dp2[l]%mod;
            int j=rr[l];
            if(r!=n-1) j-=rr[r+1];
            j=(j+mod)%mod;
            j=j*dp2[n-r-1]%mod;
            if (j==k)
                ans -= (r - l + 1);
        }
        cout << ans << '\n';
    }
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

    ll tc = 1;
    dp1[0]=1;
    fr(i,1,200005) dp1[i]=dp1[i-1]*31%mod;
    dp2[0]=1;
    int t=bp(31,mod-2);
    fr(i,1,200005) dp2[i]=t*dp2[i-1]%mod;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}