#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
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
#define MAX 100005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int check(int a[], int b[], int n, int pos, int c[])
{
    int ans1 = inf;
    int ans2 = inf;
    int l = 0, r = pos;
    if (pos != 0 && a[pos] < b[pos - 1])
    {
        // cout<<"POS1 : "<<pos<<'\n';
        if (a[pos - 1] > a[pos])
            ans1 = 1;
        else
        {
            while (l < r)
            {
                int m = (l + r) / 2;
                if (b[pos - 1] - b[m] > a[pos] && c[pos - 1] != c[m+1])
                    l = m + 1;
                else
                    r = m;
                // cout<<l<<' '<<r<<'\n';
            }
            // cout<<l<<'\n';
            if(c[pos-1]!=c[l]) ans1 = pos - l;
        }
    }

    l = pos, r = n - 1;
    if (pos != n - 1 && a[pos] < b[n - 1] - b[pos])
    {
        // cout<<"POS2 : "<<pos<<'\n';
        if (a[pos + 1] > a[pos])
            ans2 = 1;
        else
        {
            while (l < r)
            {
                int m = (l + r) / 2;
                if (b[m] - b[pos] <= a[pos] || c[pos + 1] == c[m])
                    l = m + 1;
                else
                    r = m;
                // cout<<l<<' '<<r<<'\n';
            }
            if(c[l]!=c[pos+1]) ans2 = l - pos;
        }
    }

    int ans = min(ans1, ans2);
    if (ans == inf)
        return -1;
    else
        return ans;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    in(a, n);
    int b[n];
    b[0] = a[0];
    fr(i, 1, n) b[i] = b[i - 1] + a[i];
    int c[n];
    c[0] = 0;
    fr(i, 1, n)
    {
        if (a[i] != a[i - 1])
            c[i] = c[i - 1] + 1;
        else
            c[i] = c[i - 1];
    }
    out(a,n);
    // out(c,n);
    fr(i, 0, n) cout << check(a, b, n, i, c) << " ";
    cout << '\n';
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
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}