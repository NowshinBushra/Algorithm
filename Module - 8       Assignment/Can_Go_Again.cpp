
#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
const long long int INF = 1e18;
long long int dis[10005];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int S;
    cin >> S;
    dis[S] = 0;
    
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int a, b, w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int a, b, w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
        if (dis[a] < INF && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int T;
        cin >> T;
        while (T--)
        {
            int D;
            cin >> D;

            if (dis[D] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[D] << endl;
            }
        }
    }
    return 0;
}
