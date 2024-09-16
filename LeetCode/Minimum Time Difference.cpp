#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }

        // Sort the times
        sort(minutes.begin(), minutes.end());

        
        int minDiff = 1440;  

        
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        int circularDiff = (1440 - minutes.back() + minutes[0]);
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
