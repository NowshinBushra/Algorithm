#include<bits/stdc++.h>
using namespace std;

// -----------------Recursion diye korle
int facto(int n)
{
    //base case
    if (n==0)
    {
        return 1;
    }
    
    int chotoFactorial = facto(n-1);
    return n*chotoFactorial;
}

int main()
{
    int n;
    cin>>n;

    cout<<facto(n)<<endl;
    return 0;
}


// ------------------LOOP diye korle
// int main()
// {
//     int n;
//     cin>>n;

//     int factorial = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         factorial *= i;
//     }
    

//     cout<<factorial<<endl;
//     return 0;
// }