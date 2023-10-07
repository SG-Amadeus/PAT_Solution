#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, C1, C2;
    cin >> n >> m >> C1 >> C2;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<vector<int>> edge(n, vector<int>(n, INT_MAX));
    vector<int> dis(n, INT_MAX);
    vector<int> roads(n, 0);
    vector<int> teams(n, 0);
    vector<bool> visit(n, false);

    int c1, c2, L;
    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2 >> L;
        edge[c1][c2] = edge[c2][c1] = L;
    }
    dis[C1] = 0;
    teams[C1] = weight[C1];
    roads[C1] = 1;

    for (int i = 0; i < n; ++i)
    {
        int u = -1, minn = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && edge[u][v] != INT_MAX)
            {
                if (dis[u] + edge[u][v] < dis[v])
                {
                    dis[v] = dis[u] + edge[u][v];
                    roads[v] = roads[u];
                    teams[v] = teams[u] + weight[v];
                }
                else if (dis[u] + edge[u][v] == dis[v])
                {
                    roads[v] = roads[v] + roads[u];
                    if (teams[u] + weight[v] > teams[v])
                    {
                        teams[v] = teams[u] + weight[v];
                    }
                }
            }
        }
    }
    cout << roads[C2] << " " << teams[C2] << endl;
    return 0;
}