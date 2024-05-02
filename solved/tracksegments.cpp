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
#define out(a, n) fr(i, 0, n) cout << a[i]<<' ';
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vs vector<short>
#define vb vector<bool>
#define vvi vector<vector<int>>
using namespace std;

int a[2][100003],b[100003];

int check(int k,int n,int m)
{
    int c[n+1]={0};
    fr(i,0,k)   c[b[i]]=1;
    fr(i,1,n+1)   c[i]+=c[i-1];

    fr(i,0,m)
        if((c[a[1][i]]-c[a[0][i]-1])*2>a[1][i]-a[0][i]+1)
            return 1;
    return 0;
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
        int n,m;
        cin>>n>>m;

        fr(i,0,m)
            cin>>a[0][i]>>a[1][i];

        int q;
        cin>>q;
        fr(i,0,q)
            cin>>b[i];

        int l=1,r=q;
        while(l<r)
        {
            int k=(l+r)/2;
            if(check(k,n,m))    r=k;
            else    l=k+1;
        }
        if(check(l,n,m))
            cout<<l<<'\n';
        else
            cout<<-1<<'\n';
    }
}