#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChecksPassed(int numRecords, int numPoints, const vector<int>& records) {
    int intelligence = 0;  // Intelligence points
    int strength = 0;      // Strength points
    int checksPassed = 0;  // Count of checks passed
    vector<int> neededIntelligence;
    vector<int> neededStrength;

    // Separate the checks into intelligence and strength
    for (int i = 0; i < numRecords; i++) {
        if (records[i] == 0) {
            // We gain an attribute point
            numPoints++;
        } else if (records[i] > 0) {
            // Intelligence check
            neededIntelligence.push_back(records[i]);
        } else { 
            // Strength check
            neededStrength.push_back(-records[i]); // Store as positive for easier handling
        }
    }

    // Sort the needed checks
    sort(neededIntelligence.begin(), neededIntelligence.end());
    sort(neededStrength.begin(), neededStrength.end());

    // Function to pass checks using available points
    auto passChecks = [&](vector<int>& neededChecks, int& attribute) {
        for (int neededPoints : neededChecks) {
            if (attribute >= neededPoints) {
                checksPassed++;
            } else if (numPoints > 0) {
                int requiredPoints = neededPoints - attribute;
                if (requiredPoints <= numPoints) {
                    attribute += requiredPoints;
                    numPoints -= requiredPoints;
                    checksPassed++;
                }
            }
        }
    };

    // Pass the checks
    passChecks(neededIntelligence, intelligence);
    passChecks(neededStrength, strength);

    return checksPassed;
}

int main() {
    int numRecords, numPoints;
    cin >> numRecords >> numPoints;
    vector<int> records(numRecords);
    for (int i = 0; i < numRecords; i++) {
        cin >> records[i];
    }

    cout << maxChecksPassed(numRecords, numPoints, records) << endl;
    return 0;
}