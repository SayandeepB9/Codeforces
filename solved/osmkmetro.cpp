#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) fr(i, 0, n) cin >> a[i];
#define out(a, n) fr(i, 0, n) cout << a[i];
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vll a;
        a.pb(0);
        a.pb(1);

        vll par;
        par.pb(0);
        par.pb(0);

        while (n--)
        {
            char c;
            cin>>c;
            if (c == '+')
            {
                int p,w;
                cin>>p>>w;
                par.pb(p);
                a.pb(w);
            }
            else
            {
                int l,r,key;
                cin>>l>>r>>key;

                vll v,temp;
                while(l!=r)
                {
                    while(l>r)
                    {
                        v.pb(l);
                        l=par[l];
                    }
                    while(r>l)
                    {
                        temp.pb(r);
                        r=par[r];
                    }
                }
                v.pb(l);

                ll max=a[v[0]],min=a[v[0]],s1=0,s2=0,k,vl=v.size(),tl=temp.size();
                fr(i,0,vl+tl)
                {
                    k=(i<vl)?a[v[i]]:a[temp[tl+vl-i-1]];

                    if(s1>0 || k==1)    s1+=k;
                    else    s1=0;
                    if(max<s1)  max=s1;

                    if(s2<0 || k==-1)    s2+=k;
                    else    s2=0;
                    if(min>s2)  min=s2;
                }

                if(key>=min && key<=max)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}