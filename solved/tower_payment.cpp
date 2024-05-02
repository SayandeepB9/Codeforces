#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vs vector<short>
#define vb vector<bool>
#define vvi vector<vector<int>>
using namespace std;
#define MAX 1e18

ll d[2][125];

int calc()
{
    d[0][0] = 1, d[0][1] = 0, d[1][0] = 1, d[1][1] = 1;
    int i;
    for (i = 2; i < 125; i++)
    {
        int j = 1;
        while (i - j * j >= 0)
        {
            d[0][i] += d[0][i - j * j];
            j++;
        }
        d[1][i] = d[1][i - 1] + d[0][i];
        if (d[1][i] > MAX || d[1][i] < 0)
            goto stop;
    }
stop:
    return i;
}

int lower(ll x)
{
    int l = 0, r = 121;
    while (l < r - 1)
    {
        int k = (l + r) / 2;
        if (d[1][k] == x)
            return k;
        else if (d[1][k] > x)
            r = k;
        else
            l = k;
    }
    return r;
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
    calc();

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll x;
        cin >> x;
        cout << lower(x) << '\n';
    }
}