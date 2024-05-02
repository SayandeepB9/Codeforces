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

int find(int k, int a[], int n)
{
    fr(i, 0, n) if (a[i] == k) return 1;
    return 0;
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<char> c;
        int a[n];
        fr(i, 0, n)
            a[i] = 2;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                count++;
            else
                count--;
            if (count > 0 || (count == 0 && s[i] == ')'))
                a[i] = 1;    
        }
        if (count != 0)
        {
            cout << -1 << endl;
            continue;
        }

        if (find(2, a, n) == 0 || find(1, a, n) == 0)
        {
            cout << 1 << endl;
            fr(i, 0, n)
                cout<< 1 << ' ';
            cout << endl;
        }
        else
        {
            cout << 2 << endl;
            fr(i, 0, n)
                    cout
                << a[i] << ' ';
            cout << endl;
        }
    }
}
