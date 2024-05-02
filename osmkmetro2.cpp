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

void add(vvi& a,int par,int w)
{
    if(a[0][par]>0 || w==1)
        a[0].pb(a[0][par]+w);
    else
        a[0].pb(0);

    if(a[1][par]<0 || w==-1)
        a[1].pb(a[1][par]+w);
    else
        a[1].pb(0);

    if(a[0][par]+w>a[2][par])
        a[2].pb(a[0][par]+w);
    else
        a[2].pb(a[2][par]);

    if(a[1][par]+w<a[3][par])
        a[3].pb(a[1][par]+w);
    else
        a[3].pb(a[3][par]);
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
        int n;
        cin >> n;
        vvi a(4);
        a[0].pb(0);
        a[1].pb(0);
        a[2].pb(1);
        a[3].pb(0);
        a[0].pb(1);
        a[1].pb(0);
        a[2].pb(1);
        a[3].pb(0);

        while (n--)
        {
            char c;
            cin>>c;
            if (c == '+')
            {
                int p,w;
                cin>>p>>w;
                add(a,p,w);
            }
            else
            {
                int r,key;
                cin>>r>>r>>key;
                //cout<<a[0][r]<<' '<<a[1][r]<<'\n';
                if((key>=0 && key<=a[2][r]) || (key<0 && key>=a[3][r]))
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}