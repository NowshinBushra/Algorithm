#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n==0 || n==1)
    {
        return n;
    }
    int ans= fibo(n-1) + fibo(n-2);
    return ans;
}

int main()
{
    int n;
    cin>> n;

    cout<< fibo(n);

    return 0;
}

// but ekhane onk beshi repeated call hoy. not good for big nth value (dense call).
// complexity O(n^2). So DP(Dynamic Programming) use korte hobe. Memoizing kore optimize korte hobe.