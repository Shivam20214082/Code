#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1)
            return 0; // Only one tower, no difference

        // Sort the array
        sort(arr.begin(), arr.end());

        // Initial difference between max and min heights
        int result = arr[n-1] - arr[0];

        // Explore the option of increasing or decreasing each element
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i+1] - k); 
            int max_height = max(largest, arr[i] + k); 

            if (min_height < 0) continue;

            result = min(result, max_height - min_height);
        }

        return result;
    }
};
