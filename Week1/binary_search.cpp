/*
 * Given an already shorted array of positive numbers, design an algorithm and
 * implement it using a program to find whether given key element is presnet in
 * the array or not. Also, find the total number of comparsions for each input
 * case/ Time complexity = O(n*log(n)), where n is the size of input).
 */

#include <bits/stdc++.h>
using namespace std;

void binary(vector<int> &arr, int key)
{
    int n = arr.size();
    int l = 0, r = n - 1, comp = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // cout<<arr[mid]<<"\n";
        if (++comp && arr[mid] == key)
        {
            cout << key << " is present\n";
            cout << "Total comparisions = " << comp;
            return;
        }
        else if(key>arr[mid])
            l=mid+1;
        else r=mid-1;
    }
    cout<<key <<" is not present\n";
    cout<<"Total comparisions = "<<comp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, key;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> key;
        binary(arr, key);
    }
}