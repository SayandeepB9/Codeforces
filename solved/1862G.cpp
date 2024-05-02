#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 998244353
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i]
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '; cout<<'\n'
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int b[n];
    map<ll,ll> a,dst;
    fr(i,0,n)
    {
        int x;
        cin>>x;
        b[i]=x;
        a[x]++;
    }
    auto i=a.begin();
    dst[0]=i->second-1;
    i=next(i);
    for(;i!=a.end();i++)
    {
        dst[0]+=i->second-1;
        dst[i->first-prev(i)->first]++;
    }

    ll ans=0;
    int z=n;
    ll last=0;
    for(auto i:dst)
    {
        ans+=z*(i.first-last);
        z-=i.second;
        last=i.first;
    }

    int q;
    cin>>q;
    fr(i,0,q)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        a[b[x]]--;
        if(!a[b[x]])
        {
            a.erase(b[x]);
            auto it=a.lower_bound(b[x]);
            if(it!=a.end())
            {
                dst[it->first-b[x]]--;
                ans-=it->first-b[x];
                auto ite=dst.lower_bound(it->first-b[x]);
                if(next(ite)==dst.end() & ite->second==0)   ans-=ite->first-prev(ite)->first;
                if(!dst[it->first-b[x]])    dst.erase(it->first-b[x]);
            }
            if(it!=a.begin())
            {
                auto it2=prev(it);
                dst[b[x]-it2->first]--;
                ans-=b[x]-it2->first;
                auto ite=dst.lower_bound(b[x]-it2->first);
                if(next(ite)==dst.end() & ite->second==0)   ans-=ite->first-prev(ite)->first;
                if(!dst[b[x]-it2->first])    dst.erase(b[x]-it2->first);
            }
            if(it!=a.end() & it!=a.begin())
            {
                dst[it->first-prev(it)->first]++;
                ans+=it->first-prev(it)->first;
                auto ite=dst.lower_bound(it->first-prev(it)->first);
                if(next(ite)==dst.end() & ite->second==1)   ans+=ite->first-prev(ite)->first;
            }
        }
        else    dst[0]--;

        b[x]=y;
        a[y]++;
        if(a[y]==1)
        {
            auto it=a.lower_bound(y);
            if(it!=a.begin())
            {
                auto it2=prev(it);
                dst[y-it2->first]++;
                ans+=y-it2->first;
                auto ite=dst.lower_bound(y-it2->first);
                if(next(ite)==dst.end() & ite->second==1)   ans+=ite->first-prev(ite)->first;
            }
            if(it!=--a.end())
            {
                auto it2=next(it);
                dst[it2->first-y]++;
                ans+=it2->first-y;
                auto ite=dst.lower_bound(it2->first-y);
                if(next(ite)==dst.end() & ite->second==1)   ans+=ite->first-prev(ite)->first;
            }
            if(it!=a.begin() & it!=--a.end())
            {
                dst[next(it)->first-prev(it)->first]--;
                ans-=next(it)->first-prev(it)->first;
                auto ite=dst.lower_bound(next(it)->first-prev(it)->first);
                if(next(ite)==dst.end() & ite->second==0)   ans-=ite->first-prev(ite)->first;
                if(!dst[next(it)->first-prev(it)->first])
                    dst.erase(next(it)->first-prev(it)->first);
            }
        }
        else    dst[0]++;
        cout<<a.begin()->first+ans<<' ';
    }
    cout<<'\n';
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

    ll tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}