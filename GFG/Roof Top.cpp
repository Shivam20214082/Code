class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int max_steps = 0, current_steps = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i-1]) {
                current_steps++;
                max_steps = max(max_steps, current_steps);
            } else {
                current_steps = 0;
            }
        }
        return max_steps;
    }
};
