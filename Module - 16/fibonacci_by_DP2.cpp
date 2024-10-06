#include<bits/stdc++.h>
#define ll long long
using namespace std;

// BOTTOM UP
int main()
{
    int n;
    cin>> n;
    int a[n];

    a[0]=0;
    a[1]=1;
// O(N)
    for (int i = 2; i <= n; i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    cout<< a[n]<<endl;
    return 0;
}