#include <bits/stdc++.h>
using namespace std;

int main() {
    int round;
    cin >> round;
    
    unordered_map<string, long long> Points;  // To store cumulative points
    string Winner;
    long long maxPoints = -3000;  // Initialize with smallest possible value

    while (round > 0) {
        string name;
        long long points;
        cin >> name >> points;

        // Add points to the player's score
        Points[name] += points;

        // Check if the current player has a higher score than maxPoints
        if (Points[name] > maxPoints) {
            maxPoints = Points[name];
            Winner = name;
        }
        
        round--;
    }

    cout << Winner << endl;
}
