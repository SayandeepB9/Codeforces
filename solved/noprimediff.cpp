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

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];

        if(n%2==0)
            fr(i,0,m)
                fr(j,0,n)
                    a[j][i]=j+1+n*i;
        
        else if(m%2==0)
            fr(i,0,n)
                fr(j,0,m)
                    a[i][j]=j+1+m*i;

        else
        {
            fr(i,0,(n+1)/2)
                fr(j,0,m)
                    a[i][j]=j+1+2*m*i;
            
            fr(i,0,(n-1)/2)
                fr(j,0,m)
                    a[(n+1)/2+i][j]=j+1+m*(2*i+1);
        }
        
        fr(i,0,n)
        {
            fr(j,0,m)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }
}