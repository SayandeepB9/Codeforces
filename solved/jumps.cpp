#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
using namespace std;

const int N = 1e5 + 10;
int arr[N];

int main()
{
    ll n;
    cin>>n;
    n=abs(n);

    double k=(double)n;
    int p=(int)ceil((-1.0+sqrt(1.0+8*k))/2);

    if(n%2==0)
    {
        if(p%4==0)  cout<<p<<endl;
        else if(p%4==1)  cout<<p+2<<endl;
        else if(p%4==2)  cout<<p+1<<endl;
        else  cout<<p<<endl;
    }
    else
    {
        if(p%4==0)  cout<<p+1<<endl;
        else if(p%4==1)  cout<<p<<endl;
        else if(p%4==2)  cout<<p<<endl;
        else  cout<<p+2<<endl;
    }
}
