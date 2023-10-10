#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> g;
vector<bool> visited;

void dfs(int now)
{
    visited[now] = true;
    for (auto &to : g[now])
    {
        if (!visited[to])
        {
            dfs(to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    int now, e1, e2;

    cin >> n >> m >> k;
    g.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> e1 >> e2;
        g[e1].push_back(e2);
        g[e2].push_back(e1);
    }

    for (int i = 0; i < k; i++)
    {
        int cnt = 0;
        cin >> now;
        fill(visited.begin(), visited.end(), 0);
        visited[now] = 1;
        for (int i = 1; i <= n;i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
}