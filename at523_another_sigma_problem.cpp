#include<bits/stdc++.h>

#define pb push_back
#define elif else if
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) fr(i,0,n) cin>>a[i] 
#define in1(a,n) fr(i,1,n+1) cin>>a[i]
#define out(a,n) fr(i,0,n) cout<<a[i]<<' '; cout<<"\n"
#define all(o) (o).begin(), (o).end()
#define maxHeap(a) priority_queue<a>
#define minHeap(a) priority_queue<a,vector<a>,greate<a>>
#define yess cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
#ifndef ONLINE_JUDGE
#define dbg(x) cout<<#x<<" "<<x<<endl;
#else
#define dbg(x)
#endif
#ifndef ONLINE_JUDGE
#define dbgarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#else
#define dbgarr(x)
#endif

using namespace std;

const ll m = 998244353;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        in(a,n);
      	ll sum=0;
      	fr(i,0,n){
      		sum+=(a[i]*i)%m;
      		sum%=m;
      	}
      	ll pref[n]={};
      	fr(i,0,n){
      		string s=to_string(a[i]);
      		ll len=s.size();
      		pref[i]=binpow(10LL,len);
      		if(i){
      			pref[i]+=pref[i-1];
      		}
      	}
      	fr(i,0,n){
      		sum+=(a[i]%m*((pref[n-1]-pref[i])%m))%m;
      		sum%=m;
      	}
      	cout<<sum<<endl;
    }
    return 0;

}