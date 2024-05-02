#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define mod 998244353
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
#define MAX 2e5

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin>>n;
    multiset<int> c;
    mii a;
    fr(i,0,n)
    {
        int x;
        cin>>x;
        a[x]=0;
    }
    fr(i,0,n)
    {
        int x;
        cin>>x;
        a[x]=1;
    }
    fr(i,0,n)
    {
        int x;
        cin>>x;
        c.insert(x);
    }
    multiset<int> s;
    auto it1=a.begin();
    auto it2=++a.begin();
    // for(auto i:a)
    // {
    //     cout<<i.first<<' '<<i.second<<'\n';
    // }
    while(!a.empty())
    {
        if(it1->second!=it2->second)
        {
            // cout<<it1->first<<' '<<it2->first<<'\n';
            s.insert(it2->first-it1->first);
            auto t1=it1;
            auto t2=it2;
            if(a.size()==2) break;
            if(it1==a.begin())
            {
                it1=next(next(it1));
                it2=next(next(it2));
            }
            else
            {
                it1--;
                it2++;
            }
            a.erase(t1);
            a.erase(t2);
        }
        else it1++,it2++;
    }
    // for(auto i:s) cout<<i<<' ';
    auto it3=s.begin();
    auto it4=--c.end();
    int sum=0;
    fr(i,0,n)
    {
        sum+=*it3*(*it4);
        it3++;
        it4--;
    }
    cout<<sum<<'\n';
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
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}