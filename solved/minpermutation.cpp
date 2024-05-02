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
        int n;
        cin>>n;
        int a[n];
        int pos1,pos2,pos;

        fr(i,0,n)
        {
            cin>>a[i];

            if(a[i]==n)
                pos=i;
            if(a[i]==1)
                pos1=i;
            if(a[i]==2)
                pos2=i;
        }

        if(abs(pos1-pos2)==1)
        {
            if(abs(pos1-pos)<abs(pos2-pos))
                cout<<pos1+1<<' '<<pos+1<<endl;
            else
                cout<<pos2+1<<' '<<pos+1<<endl;
        }
        else
        {
            if(pos1>pos2)
                cout<<pos1<<' '<<pos+1<<endl;
            else
                cout<<pos2<<' '<<pos+1<<endl;
        }
    }
}