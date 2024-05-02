#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct query{
    int l, r, i;
};

int n, q;
const int N = 1e5 + 69;
vector <int> adj[N];
int p[N], pp[N];
vector <pair<int, int>> e;
vector <query> b[N];
int ans[N];
set <int> sub[N];

void merge(int u, int v){
    if (sub[u].size() < sub[v].size()){
        swap(sub[u], sub[v]);
    } 
    
    for (auto x : sub[v]) sub[u].insert(x);
}

void dfs(int u, int par = -1){
    sub[u].insert(u);
    
    for (int v : adj[u]){
        if (v != par){
            dfs(v, u);
            merge(u, v);
        }
    }
    
   // cout << u << "\n";
    
    // for (auto x : sub[u]){
    //     cout << x << " ";
    // }
    // cout << "\n";
    
    for (auto qq : b[u]){
        auto id = sub[u].lower_bound(qq.l);
       // cout << qq.l << " " << qq.r << " ";
        // if (id == sub[u].end()) cout << "L ";
        // else cout << (*id) << " ";
        if (id != sub[u].end() && (*id) <= qq.r) ans[qq.i] = 1;
    //    cout << "\n";
    }
    //cout << "\n";
}

void Solve() 
{
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        b[i].clear();
        sub[i].clear();
    }
    
    for (int i = 1; i <= q; i++) ans[i] = 0;
    e.clear();
    
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        
        e.push_back({u, v});
    }
    
    for (int i = 1; i <= n; i++){
        cin >> pp[i];
        p[pp[i]] = i;
    }
    
    for (auto edge : e){
		int u = edge.f;
		int v = edge.s;
        adj[p[u]].push_back(p[v]);
        adj[p[v]].push_back(p[u]);
    }
    
    for (int i = 1; i <= q; i++){
        query ok;
        cin >> ok.l >> ok.r;
        int x; cin >> x;
        x = p[x];
        ok.i = i;
        
        b[x].push_back(ok);
    }
    
    dfs(p[1]);
    
    for (int i = 1; i <= q; i++){
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}