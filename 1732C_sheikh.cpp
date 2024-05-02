// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=skylake")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define pf push_front
#define mod 1000000007
#define mod1 998244353
#define fr(i,a,b) for(ll i=a; i<=b; i++)
#define rev(i,a,b) for(ll i=a; i>=b; i--)
#define ub upper_bound      
#define lb lower_bound
#define ld long double
#define LL __int128
#define minheappr priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>

 
const ll INF = 2e18;
const ll N = 100005;


void solve(){
            ll n; cin >> n;
            ll q; cin >> q;
            ll a[n];
            fr(i,0,n-1) cin >> a[i];
            pair<ll,ll> ans[n];
            ll pr[n+1]={0};
            ll prx[n+1] = {0};
            fr(i,0,n-1){
                pr[i+1] += pr[i] + a[i];
                prx[i+1] = (prx[i]^a[i]);
            }
            ans[n-1] = {1,0};
            // cout << pr[n] << " " << prx[];
            fr(i,0,n-2)
            {
                ll val = pr[n] - pr[i] - (prx[n]^ prx[i]);
                ll lo = i;
                ll hi = n-1;
                while(lo + 1 < hi){
                    ll mid = (lo + hi)/2;
                    ll val2 = pr[mid+1] - pr[i] - (prx[mid+1]^prx[i]);
                    if(val2==val){
                        hi = mid;
                    }
                    else{
                        lo = mid;
                    }
                }
                ans[i] = {hi - i + 1,val};
            }
            ll x,y; cin >> x >> y;
            ll mx1 = -1e17; ll finans = n; ll l; ll r;
            fr(i,0,n-1){
                mx1 = max(mx1,ans[i].second);
            }
            fr(i,0,n-1){
                // cout << ans[i].first << " " << ans[i].second << "   ";
                if(mx1 == ans[i].second && finans >= ans[i].first){
                    finans = min(finans,ans[i].first);
                    r = i+ans[i].first;
                    l = i+1;
                }
            }
            cout << l << " " << r << "\n";

}
 
signed main()
{
          #ifndef ONLINE_JUDGE
                             freopen("input.txt", "r", stdin);
                             freopen("output.txt", "w", stdout);
          #endif
          ios_base::sync_with_stdio(false);
          cin.tie(0);
          cout.tie(0);             
          ll misery=1;
          
          cin>>misery;        
          while(misery--)
          {            
                        solve();                      
          }
}