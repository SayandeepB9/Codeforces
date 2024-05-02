#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i];
#define out(a, n) fr(i, 0, n) cout << a[i];
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
using namespace std;

ll dfs(ll p_node, ll s_node, vvi &a, vll &succ)
{
    for (auto node : a[s_node])
        if (node != p_node)
            succ[s_node] += dfs(s_node, node, a, succ);

    return (succ[s_node] ? succ[s_node] : succ[s_node] = 1);
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vvi a(n + 1);
        vll successors(n + 1, 0);

        fr(i, 0, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        dfs(-1, 1, a, successors);

        cin >> n;
        while (n--)
        {
            ll x, y;
            cin >> x >> y;
            cout << successors[x] * successors[y] << endl;
        }
    }
}