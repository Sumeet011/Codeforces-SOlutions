#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n<4){
            cout << -1 << endl;
            continue;
        }
        vector<int> odd;
        vector < int> even;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                even.push_back(i);
            }
            else
            {
                odd.push_back(i);
            }
        }
        reverse(odd.begin(), odd.end());
        swap(even[0], even[1]);
        for (auto x : odd)
            cout << x << " ";
        for (auto x : even)
            cout << x << " ";
        cout << endl;
    }
}