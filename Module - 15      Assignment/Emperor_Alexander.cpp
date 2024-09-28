#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}

int leader[N];
int grp_size[N];

void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        leader[i] = -1;
        grp_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (leader[node] == -1)
        return node;
    return leader[node] = dsu_find(leader[node]);
}

void Union(int x, int y)
{
    int leaderA = dsu_find(x);
    int leaderB = dsu_find(y);
    if (leaderA != leaderB)
    {
        if (grp_size[leaderA] > grp_size[leaderB])
        {
            leader[leaderB] = leaderA;
            grp_size[leaderA] += grp_size[leaderB];
        }
        else
        {
            leader[leaderA] = leaderB;
            grp_size[leaderB] += grp_size[leaderA];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu_init(n);
    vector<Edge> EdgeList;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }
    sort(EdgeList.begin(), EdgeList.end(), comp);

    long long cost = 0;
    int edges_used = 0;
    int roads = 0;

    for (Edge ed : EdgeList)
    {
        int u_leader = dsu_find(ed.u);
        int v_leader = dsu_find(ed.v);

        if (u_leader != v_leader)
        {
            Union(ed.u, ed.v);
            cost += ed.w;
            edges_used++;
        }
        else
        {
            roads++;
        }
    }
    int rootLeader = dsu_find(1);
    bool all_connected = true;

    for (int i = 1; i <= n; i++)
    {
        if (dsu_find(i) != rootLeader)
        {
            all_connected = false;
            break;
        }
    }
    if (all_connected)
    {
        roads = (m - edges_used); 
        cout << roads << " " << cost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    return 0;
}