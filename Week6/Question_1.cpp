#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &G, int s, int d)
{
    int n = G.size();
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (top == d)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (G[top][i] == 1 && visited[i] == false)
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int s, d;
    cin >> s >> d;
    bool isPresent = dfs(arr, s - 1, d - 1);
    if (isPresent)
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Path Does Not Exist" << endl;
    return 0;
}