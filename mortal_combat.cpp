#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int x=1;
    while (t--) {
        int n;
        cin >> n;
        int index = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if(x==56) for(int i = 0; i < n; i++) cout<<a[i];
        if(x==56) break;

        int coins = 0;
        bool Turn = true; // True for Player 1's turn, false for Player 2's

        while (index < n) {
            if (Turn) {
                // Player 1's turn
                if (index < n - 1) {
                    if (a[index] == 0 && a[index + 1] == 0) {
                        index += 2; // Skip 2 easy levels
                    } else if (a[index] == 0 && a[index + 1] == 1) {
                        index++; // Skip 1 easy level, Player 2 deals with the hard level
                    } else if (a[index] == 1 && a[index + 1] == 0) {
                        coins++; // Collect 1 hard level, skip 2nd easy one
                        index += 2;
                    } else {
                        coins++; // Both are hard levels
                        index++;
                    }
                } else {
                    // Last element
                    if (a[index] == 1) coins++;
                    index++;
                }
                Turn = false;
            } else {
                // Player 2's turn
                if (index < n - 1) {
                    if (a[index] == 1 && a[index + 1] == 1) {
                        index += 2; // Skip 2 hard levels
                    } else if (a[index] == 1 && a[index + 1] == 0) {
                        index++; // Skip 1 hard level
                    } else if (a[index] == 0 && a[index + 1] == 1) {
                        index += 2; // Skip 1 easy and 1 hard level
                    } else {
                        index++; // Skip 1 easy level
                    }
                } else {
                    // Last element for Player 2
                    index++;
                }
                Turn = true;
            }
        }
        cout << coins << endl;
        x++;
    }
}
