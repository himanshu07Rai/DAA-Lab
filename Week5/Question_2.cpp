#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void equalSum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (k < arr[0] || k > arr[n - 1])
    {
        cout << "No pairs exist\n";
        return;
    }
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == k)
        {
            cout << arr[l] << " " << arr[r] << endl;
            return;
        }
        if (arr[l] + arr[r] < k)
            l++;
        else
            r--;
    }
    cout << "No pairs exist\n";
}

int main()
{
    int t, n, i, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cin >> k;
        equalSum(arr, k);
    }
    return 0;
}
