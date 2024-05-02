#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a,n) fr(i,0,n) cin>>a[i];
#define out(a,n) fr(i,0,n) cout<<a[i];
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin>>s;
        s="00"+s+"11";
        int l=s.length();
        ll count=0,counts=0,countswap=0;

        int f1=0,l0=l-1;
        while(s[f1]!='1')    f1++;
        while(s[l0]!='0')    l0--;
        
        int count0=0,count1=0,max0=f1-1,max1=l0+1,m0=0,m1=0;
        fr(i,f1,l0+1)
        {
            if(s[i]=='0')   count0++;
            else count0--;

            if(s[f1+l0-i]=='1')   count1++;
            else count1--;

            if(count0>m0)
            {
                max0=i;
                m0=count0;
            }
            if(count1>m1)
            {
                max1=f1+l0-i;
                m1=count1;
            }
            //cout<<count0<<' '<<count1<<endl;
        }

        //cout<<l0<<' '<<f1<<' '<<max0<<' '<<max1<<endl;
        fr(i,f1,max0)   if(s[i]=='1')   count++;
        rev(i,l0,max1)   if(s[i]=='0')   count++;

        if(max0+1!=max1)
        {
            counts=(max1-max0-1)/2;
            bool flag =0;
            count0=0;
            fr(i,max0+1,max1)
            {
                if(s[i]=='0')   count0++;
                else count0--;

                if(s[i]=='1' && s[i+1]=='0' && count0==-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                count+=counts-1;
                countswap++;
            }
            else    count+=counts;
        }
        
        cout<<1000000000001*count+1000000000000*countswap<<endl;
    }
}