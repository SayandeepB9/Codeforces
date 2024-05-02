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
#define pi pair<int,int>
#define si set<int>
#define mii map<int,int>
#define pq priority_queue
#define vll vector<long long>
#define vvll vector<vll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define MAX 2e5

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int cou;
vector<vector<pair<int,int>>> a(100005);
int t,t1,n,m,mi;
int visited[100005]={};
int par[100005]={};

void djikstra()
{
    pq<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> b;
    b.push({0,{0,-1}});
    while(!b.empty())
    {
        pair<int,pi> i=b.top();
        b.pop();
        int w=i.first;
        int j=i.second.first;
        int pa=i.second.second;
        if(visited[j]>1) continue;
        if(!visited[j]) par[j]=pa;
        visited[j]++;
        for(auto k: a[j]) if(k.first!=pa) b.push({w+k.second,{k.first,j}});
        if(j==n-1 && cou) cou++,t1=w;
        if(j==n-1 && !cou) cou++,t=w;
        if(cou==2) break;
    }
}

void solve()
{
    cin>>n>>m;
    fr(i,0,n) a[i].clear(),visited[i]=0,par[i]=-1;                     
    t=0,t1=inf, mi=inf,cou=0;

    fr(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        a[x].pb({y,w}),a[y].pb({x,w});
    }

    djikstra();
    if(cou>0)
    {
        int j=n-1;
        vi l;
        while(j!=0) l.pb(j),j=par[j];
        l.pb(0);
        mi=inf;
        fr(i,0,l.size())
        {
            for(auto j: a[l[i]])
            {
                if(i==0 && i!=l.size()-1 && j.first!=l[i+1]) mi=min(mi,j.second);
                if(i!=0 && i==l.size()-1 && j.first!=l[i-1]) mi=min(mi,j.second);
                if(i!=0 && i!=l.size()-1 && j.first!=l[i+1] && j.first!=l[i-1]) mi=min(mi,j.second);
            }
        }
        if(mi==inf) cout<<-1<<'\n';
        else if(cou==1) cout<<2*(t+mi)<<'\n';
        else cout<<min(t+t1,2*(t+mi))<<'\n';
    }
    else
    {
        cout<<-1<<'\n';
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
    while (tc--)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}