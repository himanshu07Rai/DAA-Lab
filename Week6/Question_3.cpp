#include <bits/stdc++.h>

using namespace std;

bool isCyclic(vector<vector<int>> &arr)
{
    int N = arr.size();
    queue<int> q;
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j])
                indegree[j]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j])
                {
                    indegree[j]--;
                    if (indegree[j] == 0)
                    {
                        q.push(j);
                    }
                }
            }
        }
    }
    if (cnt == N)
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    if (isCyclic(arr))
        cout << "Yes Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";
}