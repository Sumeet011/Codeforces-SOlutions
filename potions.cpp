#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Min-heap (priority queue) to track negative potions
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    long long health = 0;  // Current health sum
    int count = 0;         // Number of potions we can drink
    
    for (int i = 0; i < n; ++i) {
        if (health + a[i] >= 0) {
            // We can drink this potion
            health += a[i];
            count++;
            if (a[i] < 0) {
                minHeap.push(a[i]);  // Add negative potion to the heap
            }
        } else if (!minHeap.empty() && a[i] > minHeap.top()) {
            // If the current potion causes negative health but is better than the worst negative potion we drank
            health += a[i] - minHeap.top();  // Replace the worst potion with this one
            minHeap.pop();                   // Remove the worst potion from the heap
            minHeap.push(a[i]);              // Add the current potion to the heap
        }
    }
    
    cout << count << endl;
    return 0;
}
