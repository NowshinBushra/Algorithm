#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N];
int grp_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i]= -1;
        grp_size[i]=1;
    }
    par[1]=2;
    par[2]=3;           
    par[5]=6;
    par[6]=7;
}
int dsu_find(int node)
{
    if(par[node]==-1)
    return node;
    int leader= dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int lead_A = dsu_find(node1);
    int lead_B = dsu_find(node2);
    par[lead_A]=lead_B;
}

int main()
{
    dsu_initialize(8);
    // for (int i = 1; i <= 7; i++)
    //     cout << par[i] << " ";

    dsu_union(1,5);
    cout << dsu_find(2) << endl;

    return 0;
}