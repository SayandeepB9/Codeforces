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

int build(int m[], int n, int s[], int i)
{
    if(i>=n) return (s[i]=m[i-n]);
    else return (s[i]=min(build(m,n,s,2*i),build(m,n,s,2*i+1)));
}

int buildx(int m[], int n, int s[], int i)
{
    if(i>=n) return s[i]=m[i-n];
    else return (s[i]=max(buildx(m,n,s,2*i),buildx(m,n,s,2*i+1)));
}

int qmx(int n, int m[], int l, int r, int ls, int rs, int i)
{
    if(l==ls && r==rs || i>=n) return m[i];
    int mid=(ls+rs)/2;
    if(l>mid) return qmx(n,m,l,r,mid+1,rs,2*i+1);
    else if(r<=mid) return qmx(n,m,l,r,ls,mid,2*i);
    else return max(qmx(n,m,l,mid,ls,mid,2*i),qmx(n,m,mid+1,r,mid+1,rs,2*i+1));
}

int qmi(int n, int m[], int l, int r, int ls, int rs, int i)
{
    if((l==ls && r==rs) || i>=n) return m[i];
    int mid=(ls+rs)/2;
    if(l>mid) return qmi(n,m,l,r,mid+1,rs,2*i+1);
    else if(r<=mid) return qmi(n,m,l,r,ls,mid,2*i);
    else return min(qmi(n,m,l,mid,ls,mid,2*i),qmi(n,m,mid+1,r,mid+1,rs,2*i+1));
}

// int qmi(int m[], int l, int r, int ls, int rs, int i)
// {
//     int mi=inf;
//     fr(j,l,r+1)  mi=min(mi,m[j]);
//     return mi;
// }

// int qmx(int m[], int l, int r, int ls, int rs, int i)
// {
//     int mi=0;
//     fr(j,l,r+1)  mi=max(mi,m[j]);
//     return mi;
// }

int dfs(vector<unordered_set<int>>& c, int v[], int i)
{
    if(v[i]) return i;
    v[i]=1;
    int m=i;
    for(auto j:c[i])
    {
        m=max(max(m,j),dfs(c,v,j));
    }
    return m;
}

void solve()
{
    int n;
    cin>>n;
    vvi a(n,vi(2));
    fr(i,0,n) a[i][0]=a[i][1]=-1;
    int t=(1ll<<(int)(log2(n-1)+2));
    int b[2*n],mi[t]={},ma[t]={},sn[2*t]={},sx[2*t]={};
    fr(i,0,2*n)
    {
        cin>>b[i];
        b[i]--;
        if(a[b[i]][0]==-1) a[b[i]][0]=i;
        else a[b[i]][1]=i;
    }
    fr(i,0,2*n)
    {
        mi[i]=a[b[i]][0];
        ma[i]=a[b[i]][1]; 
    }
    // out(b,2*n);
    // out(mi,t);
    // out(ma,t);
    build(mi,t,sn,1);
    buildx(ma,t,sx,1);
    // out(sn,2*t);
    // out(sx,2*t);

    int v[2*n]={};
    vector<unordered_set<int>> c(2*n);
    fr(i,0,n)
    {
        int mn=qmi(t,sn,a[i][0],a[i][1],0,t-1,1);
        int mx=qmx(t,sx,a[i][0],a[i][1],0,t-1,1);
        c[a[i][0]].insert(mn);
        c[a[i][0]].insert(mx);
        c[mx].insert(a[i][0]);
        c[mn].insert(a[i][0]);
        c[a[i][1]].insert(mn);
        c[a[i][1]].insert(mx);
        c[mx].insert(a[i][1]);
        c[mn].insert(a[i][1]);
    }
    // out(b,2*n);
    // for(auto i:c)
    // {
    //     cout<<"i : ";
    //     for(auto j:i) cout<<j<<' ';
    //     cout<<'\n';
    // }

    int co=0,count=0,mul=1,prev=0;
    fr(i,0,2*n)
    {
        if(!v[i]) i=dfs(c,v,i);
        fr(j,prev,i+1)
        {
            count+=v[j];
        }
        mul=mul*count%mod;
        prev=i+1;
        count=0;
        co++;
    }
    cout<<co<<' '<<mul<<'\n';
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