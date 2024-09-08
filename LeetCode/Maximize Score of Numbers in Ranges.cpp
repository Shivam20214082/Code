#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool check(vector<int>& start, int d, int mid) {
        int prev = start[0];
        for (int i = 1; i < start.size(); i++) {
            int next = prev + mid;
            if (next > start[i] + d) return false;
            prev = max(next, start[i]);
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int l = 0, h = INT_MAX;
        int ans = 0;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(start, d, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> start1 = {6, 0, 3};
    int d1 = 2;
    cout << solution.maxPossibleScore(start1, d1) << endl;  // Output: 4

    vector<int> start2 = {2, 6, 13, 13};
    int d2 = 5;
    cout << solution.maxPossibleScore(start2, d2) << endl;  // Output: 5

    return 0;
}
