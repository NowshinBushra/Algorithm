#include <bits/stdc++.h>
using namespace std;
  
int n, m;
char graph[1001][1001]; 
bool vis[1001][1001]; 

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y) 
{
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !vis[x][y])
        return true;
    else
        return false;
}

int dfs(int si, int sj) 
{
    vis[si][sj] = true;
    int area = 1; 
    for (int i = 0; i < 4; i++) 
    {
        int ci = si + dx[i]; 
        int cj = sj + dy[i];
        if (valid(ci, cj)) 
        {
            area += dfs(ci, cj); 
        }
    }
    return area; 
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> graph[i][j];
        }
    }
    int min_area = INT_MAX;
    bool has_component = false;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (graph[i][j] == '.' && !vis[i][j]) 
            {
                int area = dfs(i, j);
                has_component = true;
                min_area = min(min_area, area);
            }
        }
    }
    if (has_component) 
    {
        cout << min_area << endl;
    } 
    else 
    {
        cout << -1 << endl;
    }
    return 0;
}