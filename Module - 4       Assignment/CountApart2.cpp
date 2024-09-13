
#include<bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][10001];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n,m;

bool valid(int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<m && graph[x][y]=='.')
        return true;
    else
        return false;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int room = 1;

    for(int i=0; i<4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];

        if (valid(ci,cj) && vis[ci][cj] == false)
        {
            room = room + dfs(ci,cj);
        }
    }
    return room;
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    vector<int>apartment;

    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (graph[i][j]=='.' && vis[i][j]==false)
            {
                int count = dfs(i,j);
                apartment.push_back(count);
            }            
        }
    }

    sort(apartment.begin(), apartment.end());
    if (apartment.empty())
    {
        cout<< 0 << endl;
    }
    else
    {     
        for(int ans : apartment)
        {
            cout<< ans<< " ";
        }
        cout<<endl;
    }

    return 0;
}