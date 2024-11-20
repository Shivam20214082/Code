class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int> ans;
        int candidate1 = 0, candidate2 = 0; 
        int countSoFar1 = 0, countSoFar2 = 0;
        
        // Find the candidates
        for (const int num : nums) {
            if (num == candidate1) {
                ++countSoFar1;
            } else if (num == candidate2) {
                ++countSoFar2;
            } else if (countSoFar1 == 0) {
                candidate1 = num;
                ++countSoFar1;
            } else if (countSoFar2 == 0) {
                candidate2 = num;
                ++countSoFar2;
            } else {
                --countSoFar1;
                --countSoFar2;
            }
        }
        
        // Validate the candidates
        int count1 = 0, count2 = 0;
        for (const int num : nums) {
            if (num == candidate1) {
                ++count1;
            } else if (num == candidate2) {
                ++count2;
            }
        }
        
        // Add valid candidates to result
        if (count1 > nums.size() / 3) {
            ans.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            ans.push_back(candidate2);
        }
        
        sort(ans.begin(), ans.end()); 
        return ans;
    }
};