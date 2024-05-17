#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
#define mod1 1000000007
#define inf 1e9+1
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(ij, 0, n) cout << a[ij] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MA 10005

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"X"<<endl;
        int q;
        cin>>q;
        fr(i,0,q)
        {
            int x;
            cin>>x;
            switch(x)
            {
                case 2: cout<<1<<' '<<1<<endl; break;
            }
        }
    }
    else if(n==2)
    {
        cout<<"X"<<endl;
        cout<<"XXO"<<endl;
        int q;
        cin>>q;
        fr(i,0,q)
        {
            int x;
            cin>>x;
            switch(x)
            {
                case 2: cout<<1<<' '<<1<<endl; break;
                case 14: cout<<2<<' '<<2<<endl; break;
                case 7: cout<<1<<' '<<2<<endl; break;
                case 8: cout<<2<<' '<<1<<endl; break;
            }
        }
    }
    else
    {
        cout<<"X"<<endl;
        cout<<"XXO"<<endl;
        cout<<"XOXO"<<endl;
        int q;
        cin>>q;
        fr(i,0,q)
        {
            int x;
            cin>>x;
            switch(x)
            {
                case 2: cout<<1<<' '<<1<<endl; break;
                case 14: cout<<2<<' '<<2<<endl; break;
                case 7: cout<<1<<' '<<2<<endl; break;
                case 8: cout<<2<<' '<<1<<endl; break;
                case 15: cout<<3<<' '<<3<<endl; break;
                case 11: cout<<1<<' '<<3<<endl; break;
                case 9: cout<<3<<' '<<1<<endl; break;
                case 17: cout<<2<<' '<<3<<endl; break;
                case 19: cout<<3<<' '<<2<<endl; break;
            }
        }
    }
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();

    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc=1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}