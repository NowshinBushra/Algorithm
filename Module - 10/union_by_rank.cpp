#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int grp_size[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i]= -1;
        grp_size[i]=1;
        level[i]=0;
    }
}
int dsu_find(int node)
{
    if(par[node]==-1)
    return node;
    int leader= dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

// dsu_union() theke optimized
void dsu_union_by_level(int node1, int node2)
{
    int lead_A = dsu_find(node1);
    int lead_B = dsu_find(node2);
    if(level[lead_A] > level[lead_B])
    {
        par[lead_B]=lead_A;
    }
    else if (level[lead_B] > level[lead_A])
    {
        par[lead_A]=lead_B;
    }
    else {
        par[lead_A]=lead_B;
        level[lead_B]++;
    }
    
}
int main()
{
    dsu_initialize(7);
    dsu_union_by_level(1,2);
    dsu_union_by_level(2,3);
    dsu_union_by_level(4,5);
    dsu_union_by_level(5,6);
    // dsu_union_by_rank(1,4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}