#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        unordered_map<int, int> nums;
        nums[0] = 1;
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += s.at(i) - '0';
            if (nums.find(sum - i - 1) != nums.end())
            {
                ans += nums[sum - i - 1];
            }
            nums[sum - i - 1]++;
        }
        cout << ans << endl;
    }
}