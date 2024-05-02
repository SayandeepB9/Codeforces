#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
using namespace std;

const int N = 1e5 + 10;
int arr[N];

int main()
{

    ll tc;
    cin >> tc;
    while (tc--)
    {
        int x,k;
        cin>>x>>k;
        if(x%k!=0)
            cout<<1<<endl<<x<<endl;
        else
            cout<<2<<endl<<x-1<<' '<<1<<endl;
    }
}
