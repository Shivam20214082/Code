#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 1, maxReach = arr[0], steps = arr[0];

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;
                steps = maxReach - i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << solution.minJumps(arr1) << endl;

    vector<int> arr2 = {1, 4, 3, 2, 6, 7};
    cout << solution.minJumps(arr2) << endl;

    vector<int> arr3 = {0, 10, 20};
    cout << solution.minJumps(arr3) << endl;

    return 0;
}
