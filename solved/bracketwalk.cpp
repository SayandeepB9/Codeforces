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
#define out(a, n) fr(i, 0, n) cout << a[i]<<' ';
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vll vector<long long>
#define vs vector<short>
#define vb vector<bool>
#define vvi vector<vector<int>>
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

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    set<int> a,b;
    fr(i,1,n)
        if(s[i]=='(' && s[i-1]=='(')
            a.insert(i);
        else if(s[i]==')' && s[i-1]==')')
            b.insert(i);

    int c[q];
    fr(i,0,q)
    {
        cin>>c[i];
        c[i]--;
    }
        
    fr(i,0,q)
    {
        if(n%2)
        {
            cout<<"NO\n";
            continue;
        }

        int k=c[i];
        s[k]=(s[k]=='(')?')':'(';

        if(k==0)
        {
            if(s[0]==')')
            {
                if(s[1]=='(')   a.erase(1);
                else    b.insert(1);
            }
            else
            {
                if(s[1]=='(')   a.insert(1);
                else    b.erase(1);
            }
        }
        else if(k==n-1)
        {
            if(s[k]==')')
            {
                if(s[k-1]=='(')   a.erase(k);
                else    b.insert(k);
            }
            else
            {
                if(s[k-1]=='(')   a.insert(k);
                else    b.erase(k);
            }
        }
        else
        {
            if(s[k]==')')
            {
                if(s[k+1]=='(')   a.erase(k+1);
                else    b.insert(k+1);

                if(s[k-1]=='(')   a.erase(k);
                else    b.insert(k);
            }
            else
            {
                if(s[k+1]=='(')   a.insert(k+1);
                else    b.erase(k+1);

                if(s[k-1]=='(')   a.insert(k);
                else    b.erase(k);
            }
        }

        if(s[0]==')' || s[n-1]=='(')
            cout<<"NO\n";
        else if(a.empty() || b.empty())
        {
            if(a.empty() && b.empty())
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            if(*(a.begin())<*(b.begin()) && *--(a.end())<*--(b.end()))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}