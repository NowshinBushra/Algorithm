#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {0, 0, -1, 1}; // row er move
int dy[4] = {1, -1, 0, 0}; // col er move
map<pair<int, int>, pair<int, int>> par;

int n, m;

char graph[N][N];

bool valid(int ci, int cj)
{

    if (ci >= 0 && ci < n && cj >= 0 && cj < m && graph[ci][cj] != '#' && !vis[ci][cj])
    {
        return true;
    }
    else
        return false;
}

bool bfs(int si, int sj, int &ei, int &ej)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        if (graph[node.first][node.second] == 'D') {
            ei = node.first;
            ej = node.second;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                par[{ci, cj}] = {node.first, node.second};
            }
        }
    }
    return false;
}

int main()
{

    cin >> n >> m;

    memset(vis, false, sizeof(vis));

    int start_i, start_j, end_i, end_j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') {
                start_i = i;
                start_j = j;
            }
        }
    }
    bool found = bfs(start_i, start_j, end_i, end_j);

    if(found)
    {
        int xi=end_i;
        int xj=end_j;
        while(graph[xi][xj] != 'R')
        {
            graph[xi][xj]='X';
        int Nxi = par[{xi, xj}].first;
        xj = par[{xi, xj}].second;
        xi = Nxi;
        }
        graph[start_i][start_j] = 'R';
        graph[end_i][end_j] = 'D';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    cout << endl;
}