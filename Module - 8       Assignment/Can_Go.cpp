#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
using namespace std;

const long long int INF = 1e18;
int N, E;

vector<pair<int, int>> adj[100005];
long long int dis[100005];
bool vis[100005];

void dijkstra(int src)
{

    for (int i = 1; i <= N; i++)
    {
        dis[i] = INF;
        //vis[i] = false;
    }

    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;
        int parentCost = parent.first;

        //if (vis[parentNode]) continue; // Skip if already visited

        vis[parentNode] = true;

        for (auto child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;

            if (dis[parentNode] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main()
{
    cin >> N >> E;

    while (E--)
    {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({W, B});
    }

    int S;
    cin >> S;
    dijkstra(S);

    int T;
    cin >> T;

    while (T--)
    {
        int D, DW;
        cin >> D >> DW;

        if (dis[D] <= DW)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }

    return 0;
}