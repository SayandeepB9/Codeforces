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
        int count=1,a=0,n;
        string s;
        cin>>n>>s;
        vi k;
        k.pb(a);

        for (int i = 0; i < n; i++)
        {
            if(s[i]=='>')
            {
                if(i!=0)
                {    if(s[i-1]=='<')
                        a=*max_element(k.begin(), k.end());}
                a--;
            }
            else
            {
                if(i!=0)
                {    if(s[i-1]=='>')
                        a=*min_element(k.begin(), k.end());}
                a++;
            }

            vector<int>::iterator it = find(k.begin(), k.end(), a);
            if (it == k.end())
            {
                k.pb(a);
                count++;
            }
        }
        cout<<count<<endl; 
    }
}
