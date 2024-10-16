#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        long long ans = 0;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            long long start = v[i];
            if (v[i] <= x)
            {
                ans++;
            }
            else
            {
                start = 0;
            }
            for (int j = i + 1; j < n; j++)
            {
                start += v[j];
                if (start <= x)
                {
                    ans++;
                }
                else
                {
                    start = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}