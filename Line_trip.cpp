#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int start = 0;
        int Max = -1;
        for (int i = 0; i < n; i++)
        {
            Max = max(Max, v[i] - start);
            start = v[i];
        }
        cout << max(Max, 2 * (x - v[n - 1])) << endl;
    }
}