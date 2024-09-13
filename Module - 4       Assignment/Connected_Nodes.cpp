#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;

    vector<int> mat[N];

    while (E--)
    {
        int A, B;
        cin >> A >> B;

        mat[A].push_back(B);
        mat[B].push_back(A);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X;
        cin >> X;

        if (mat[X].empty())
        {
            cout << "-1" << endl;
        }
        
        else
        {
            sort(mat[X].begin(), mat[X].end(), greater<int>());

            for (int i = 0; i < mat[X].size(); i++)
            {
                cout << mat[X][i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}