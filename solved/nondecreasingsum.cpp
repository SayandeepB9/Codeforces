#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a,n) fr(i,0,n) cin>>a[i];
#define out(a,n) fr(i,0,n) cout<<a[i];
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
using namespace std;

// const int N = 1e5 + 10;
// int arr[N];

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int a[n];

        in(a,n);

        fr(i,0,n) cout<<n+1-a[i]<<' ';
        cout<<endl;
    }
}