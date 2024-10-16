#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> potions(n);
    for (int i = 0; i < n; i++) {
        cin >> potions[i];
    }

    long long health = 0;  // Current health
    long long count = 0;   // Number of potions drunk
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;  // Min-heap to store the negative potions we've drunk

    for (int i = 0; i < n; i++) {
        if (health + potions[i] >= 0) {
            // If drinking the potion keeps health non-negative, drink it
            health += potions[i];
            minHeap.push(potions[i]);  // Store the potion we drank
            count++;
        } else {
            // If drinking this potion would drop health below zero, check if we can replace
            if (!minHeap.empty() && potions[i] > minHeap.top()) {
                // Replace the most harmful potion with the current one if it's less negative
                health -= minHeap.top();  // Remove the most harmful potion's effect
                minHeap.pop();  // Remove that potion
                health += potions[i];  // Drink the current potion
                minHeap.push(potions[i]);  // Add the current potion to the heap
            }
        }
    }

    cout << count << endl;  // Output the maximum number of potions we can drink
    return 0;
}
