class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            if (rankMap.find(arr[i]) == rankMap.end()) {
                rankMap[arr[i]] = rank++;
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = rankMap[ans[i]];
        }
        
        return ans;
    }
};
