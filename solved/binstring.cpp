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
        string s;
        cin>>s;

        int l=s.length();
        if(s[0]=='?')
            s[0]='0';
        if(s[l-1]=='?')
            s[l-1]='1';

        fr(i,1,l-1)
            if(s[i]=='?')
            {
                if(s[i-1]=='0')
                    s[i]='0';
                else
                    s[i]='1';
            }

        cout<<s<<endl;
    }
}