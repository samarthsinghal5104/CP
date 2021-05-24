#include <bits/stdc++.h>
#define F(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main()
{
    vector<int> arr;
    int n, i, k;
    cout << "enter n\n";
    cin >> n;
    cout << "enter " << n << " values\n";
    F(i, n)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    cout << "enter k \n";
    cin >> k;
    deque<int> maxK(k);
    i = 0;
    while (i < k)
    {
        while (!maxK.empty() && arr[i] >= arr[maxK.back()])
        {
            maxK.pop_back();
        }
        maxK.push_back(i);
        i++;
    }
    while (i < n)
    {
        cout << arr[maxK.front()] << " ";
        while (!maxK.empty() && maxK.front() <= i - k)
        {
            maxK.pop_front();
        }
        while (!maxK.empty() && arr[i] > arr[maxK.back()])
        {
            maxK.pop_back();
        }
        maxK.push_back(i);
        i++;
    }
}