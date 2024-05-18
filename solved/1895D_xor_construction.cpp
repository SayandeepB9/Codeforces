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

struct node{
    struct node *a,*b;
};

struct node* newnode()
{
    struct node* n = new node();
    n->a=NULL;
    n->b=NULL;
    return n;
}

void insert(int n, struct node* root)
{
    struct node* temp=root;
    rev(i,24,0)
    {
        int k=((n>>i)&1);
        if(k) {if(temp->b==NULL) temp->b=newnode(); temp=temp->b;}
        else {if(temp->a==NULL) temp->a=newnode(); temp=temp->a;}
    }
}

int get(int n, struct node* root)
{
    int ma=0;
    struct node* temp=root;
    rev(i,24,0)
    {
        int k=((n>>i)&1);
        if(k)
        {
            if(temp->a!=NULL) ma|=(1<<i), temp=temp->a;
            else temp=temp->b;
        }
        else
        {
            if(temp->b!=NULL) ma|=(1<<i), temp=temp->b;
            else temp=temp->a;
        }
    }
    return ma;
}

void solve()
{
    int n;
    cin>>n;
    int a[n-1];
    in(a,n-1);
    int c[n-1];
    c[0]=a[0];
    fr(i,1,n-1) c[i]=(c[i-1]^a[i]);
    struct node* root =  newnode();
    fr(i,0,n-1) insert(c[i],root);
    int j=-1;
    while(1)
    {
        j++;
        int x=get(j,root);
        if(x<n) break;
    }
    cout<<j<<' ';
    fr(i,0,n-1) cout<<(j^c[i])<<' ';
    cout<<'\n';
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