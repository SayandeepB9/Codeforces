#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    
    while(t)
    {
        t--;
        int x,y;
        cin>>x>>y;
        if(((x+1)/2)%2==1)
        {
            if(((y+1)/2)%2==1)
                cout<<"Second"<<'\n';
        }
        else
            cout<<"First"<<'\n';
    }
    return 0;
}
