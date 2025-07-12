#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m;

    vector<vector<vector<int>>> colorGraph(m + 1, vector<vector<int>>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        colorGraph[c][a].push_back(b);
        colorGraph[c][b].push_back(a);
    }

    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int cnt = 0;
        for (int c = 1; c <= m; c++)
        {
            vector<bool> visited(n + 1, false);
            queue<int> que;
            que.push(u);
            visited[u] = true;

            while (!que.empty())
            {
                int node = que.front();
                que.pop();
                for (int neighbor : colorGraph[c][node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }

            if (visited[v])
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}