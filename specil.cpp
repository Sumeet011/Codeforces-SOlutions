#include <iostream>
#include <deque>

using namespace std;


bool isBetterToMoveForwardOneStep(const deque<int>& arr, int idx) {
    return arr[idx] < arr[idx + 1];
}

bool isBetterToMoveForwardTwoSteps(const deque<int>& arr, int idx) {
    return arr[idx] + arr[idx - 1] < arr[idx + 1] + arr[idx + 2];
}

bool isBetterToMoveBackward(const deque<int>& arr, int idx) {
    return arr[idx] < arr[idx - 1];
}
int main() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int n, k, z;
        cin >> n >> k >> z;

        deque<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long sum = 0;
        int idx = 0;

        while (k > 0) {
            if (idx > 1 && idx < n - 3 && z != 0) {
                if (isBetterToMoveForwardTwoSteps(arr, idx)) {
                    idx += 2;
                    k--;
                    sum += arr[idx - 1] + arr[idx];
                } else if (isBetterToMoveForwardOneStep(arr, idx)) {
                    idx++;
                    k--;
                    sum += arr[idx];
                } else if (isBetterToMoveBackward(arr, idx)) {
                    idx--;
                    k--;
                    z--;
                    sum += arr[idx];
                } else {
                    idx++;
                    k--;
                    sum += arr[idx];
                }
            } else if (idx > 0 && idx < n - 2 && z != 0) {
                if (isBetterToMoveForwardOneStep(arr, idx)) {
                    idx++;
                    k--;
                    sum += arr[idx];
                } else if (isBetterToMoveBackward(arr, idx)) {
                    idx--;
                    k--;
                    z--;
                    sum += arr[idx];
                } else {
                    idx++;
                    k--;
                    sum += arr[idx];
                }
            } else {
                idx++;
                k--;
                sum += arr[idx];
            }
        }

        cout << sum << endl;
    }

    return 0;
}
