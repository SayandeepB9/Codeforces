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
#define in(a, n) fr(ij, 0, n) cin >> a[ij]
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

#include <vector>

class TwoSAT {
private:
    int n;
    std::vector<std::vector<int>> adj, adj_t;
    std::vector<bool> used;
    std::vector<int> order, comp;
    std::vector<bool> assignment;

    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

public:
    TwoSAT(int size) : n(size), adj(2 * n), adj_t(2 * n), used(2 * n), comp(2 * n), assignment(n) {}

    bool solve() {
        order.clear();
        used.assign(2 * n, false);
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(2 * n, -1);
        for (int i = 0, j = 0; i < 2 * n; ++i) {
            int v = order[2 * n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n, false);
        for (int i = 0; i < 2 * n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }

    std::vector<bool> get_assignment() {
        return assignment;
    }
};

void solve()
{
    int n;
    cin>>n;
    int g[3][n];
    fr(i,0,3) in(g[i],n);
    TwoSAT ts(n);
    fr(i,0,n)
    {
        int a=g[0][i], b=g[1][i], c=g[2][i];
        ts.add_disjunction(abs(a)-1, a>0, abs(b)-1, b>0);
        ts.add_disjunction(abs(a)-1, a>0, abs(c)-1, c>0);
        ts.add_disjunction(abs(c)-1, c>0, abs(b)-1, b>0);
    }
    cout<<(ts.solve()?"YES":"NO")<<'\n';
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