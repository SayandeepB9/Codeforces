#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define BIG 998244353
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define mkp make_pair
#define pb emplace_back

ll powerM(ll x, ll y , ll m=MOD){
    ll res=1;
    while(y){
        if(y & 1)res=(res*x)%m;
        y>>=1;
        x=(x*x)%m;
    }
    return res%m;
}

void solve(){
    ll n,k;
    cin>>n;
    ll on=__builtin_popcountll(n);
    if(on<3){
        cout<<"0\n";
        return;
    }
    ll ans=(powerM(3,on)-(3*powerM(2,on))%MOD+3+MOD)%MOD;
    cout<<ans<<nline;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();
}