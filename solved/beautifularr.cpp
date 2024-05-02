#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,min;
    cin>>t;
    while(t--)
    {
        int n,a,odd=0;
        cin>>n>>a;
        min=a;n--;
        if(a%2==1)
            odd=1;
        while(n--)
        {
            cin>>a;
            if(a<min)
                min=a;
            if(a%2==1)
                odd=1;
        }
        if(min%2==0 && odd==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}