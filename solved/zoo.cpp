#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b)
            cout<<"NO"<<endl;
        else if(a==b)
            cout<<"YES"<<endl;
        else
        {
            int count=0;
            while(b)
            {
                    count+=(a%2)-(b%2);
                    a/=2;
                    b/=2;
                    if(count<0)
                        break;
            }
            if(count<0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
}