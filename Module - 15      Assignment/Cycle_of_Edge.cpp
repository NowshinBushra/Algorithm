
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;  
int par[N];  
int n, m;  

int find(int u) 
{
    if (u != par[u]) 
    {
        par[u] = find(par[u]);
    } 
    return par[u];
}

bool valid(int u, int v) 
{
    int U = find(u);
    int V = find(v);
    if (U == V) 
    {
        return false;
    } 
    par[V] = U;
    return true;
}

int main() 
{
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) 
    {
        par[i] = i; 
    }
    int cycle_count = 0;  
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;  
        if (!valid(u, v)) 
            cycle_count++;  
    }
    cout << cycle_count << endl;  
    return 0;
}