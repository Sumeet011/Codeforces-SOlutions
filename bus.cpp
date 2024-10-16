#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        int happy = 0;
        int unhappy = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            happy += (a / 2) * 2;  // Add the largest even part of 'a' to happy
            unhappy += (a % 2);    // Count the remaining part (if odd) as unhappy
            r -= (a / 2);          // Deduct the happy parts from resources
        }

        if (r >= unhappy) {
            cout << happy + unhappy << endl;
        } else {
            while (unhappy > 0) {
                if (r >= unhappy) {
                    happy += unhappy;
                    break;
                } else {
                    unhappy -= 2;  // Reduce the unhappy count by 2 (since each resource can fix 2 unhappy people)
                    r--;           // Decrease resources for each operation
                }
            }
            cout << happy << endl;
        }
    }
}
