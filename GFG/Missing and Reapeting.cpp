class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(2);
        
        // Mark visited indices as negative
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0) {
                result[0] = abs(arr[i]);  // Repeating number
            } else {
                arr[index] *= -1;
            }
        }
        
        // Find missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                result[1] = i + 1;  // Missing number
                break;
            }
        }
        
        return result;
    }
};
