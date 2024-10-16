#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, window_size;
        cin >> n >> window_size;
        unordered_map<int, int> frequency_map;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;
            frequency_map[element]++;
        }

        vector<pair<int, int>> frequency_vector(frequency_map.begin(), frequency_map.end());
        sort(frequency_vector.begin(), frequency_vector.end());

        long long max_sum = 0;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < frequency_vector.size(); right++)
        {
            current_sum += frequency_vector[right].second;

            while ((right - left + 1 > window_size) || (right > left && frequency_vector[right].first - frequency_vector[right - 1].first > 1))
            {
                current_sum -= frequency_vector[left].second;
                left++;
            }

            max_sum = max(max_sum, current_sum);
        }

        cout << max_sum << endl;
    }

    return 0;
}