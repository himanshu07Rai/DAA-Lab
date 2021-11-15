#include <bits/stdc++.h>

using namespace std;

bool bipartiteBfs(int src, vector<vector<int>> &g, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : g[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool checkBipartite(vector<vector<int>> &g)
{
    int V = g.size();
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, g, color))
                return false;
        }
    }
    return true;
}

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> g(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> g[i][j];
        }
    }
    if (checkBipartite(g))
        cout << "Yes Bipartite\n";
    else
        cout << "Not Bipartite\n";
}