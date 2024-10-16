#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    int left = 0;
    long long current_sum = 0, max_sum = 0;

    deque<int> max_deque, min_deque;

    for (int right = 0; right < n; right++) {
        current_sum += friends[right].second;

        while (!max_deque.empty() && friends[max_deque.back()].first <= friends[right].first) {
            max_deque.pop_back();
        }
        max_deque.push_back(right);

        while (!min_deque.empty() && friends[min_deque.back()].first >= friends[right].first) {
            min_deque.pop_back();
        }
        min_deque.push_back(right);

        while (friends[max_deque.front()].first - friends[min_deque.front()].first >= d) {
            current_sum -= friends[left].second;
            left++;

            while (!max_deque.empty() && max_deque.front() < left) {
                max_deque.pop_front();
            }

            while (!min_deque.empty() && min_deque.front() < left) {
                min_deque.pop_front();
            }
        }

        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;

    return 0;
}