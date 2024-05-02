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
#define out(a, n) fr(i, 0, n) cout << a[i] << ' '
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
# define MAX 1e5
using namespace std;

ll dfs(ll node, vvi &a, vvi& visited, ll s_node, ll s)
{
    for (auto node_new : a[node])
    {
        if(node_new==s)    continue;
        if(visited[node_new].empty())
            visited[node_new].pb(s_node);
        else if(visited[node_new][0]==s_node)
            continue;
        else
        {
            visited[node_new].pb(s_node);
            return node_new;
        }
        ll b=dfs(node_new, a, visited, s_node, s);
        if(b)   return b;
    }
    return 0;
}

ll dfs_path(ll e_node, vvi& visited, vvi& a, ll s_node, ll n_node, vi& path)
{
    for(auto node: a[n_node])
    {
        if(visited[node].size()>=1 && (visited[node][0]==s_node || visited[node][1]==s_node))
        {
            if(node==e_node)
            {
                path.pb(node);
                return 1;
            }
            visited[node]={};
            if(dfs_path(e_node, visited, a, s_node, node, path))
            {
                path.pb(node);
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    int n,m,s;
    cin>>n>>m>>s;
    vvi a(n+1);
    vvi visited(n+1);

    fr(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }

    ll b;
    for(auto node: a[s])
    {
        if(!visited[node].empty())
        {
            b = node;
            visited[node].pb(b);
            break;
        }
        visited[node].pb(node);
        b = dfs(node, a, visited, node, s);
        if(b)   break;
    }
    if(b)
    {
        cout<<"Possible\n";
        vi path1,path2;

        ll s1 = visited[b][0];
        ll s2 = visited[b][1];
        if(s1!=b)   visited[s1]={};
        if(s2!=b)   visited[s2]={};
        dfs_path(b, visited, a, s1, s1, path1);
        dfs_path(b, visited, a, s2, s2, path2);
        path1.pb(s1);
        path1.pb(s);
        path2.pb(s2);
        path2.pb(s);

        cout<<path1.size()<<'\n';
        for(auto i= path1.end(); i!=path1.begin();)
            cout<<*--i<<' ';
        cout<<'\n';
        cout<<path2.size()<<'\n';
        for(auto i= path2.end(); i!=path2.begin();)
            cout<<*--i<<' ';
        cout<<'\n';
    }
    else    cout<<"Impossible\n";
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

    ll tc = 1;
    while (tc--)
    {
        solve();
    }
}