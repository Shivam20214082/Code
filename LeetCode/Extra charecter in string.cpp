class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (const string& word : dictionary) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = min(dp[i], dp[i - len]);
                }
            }
        }
        
        return dp[n];
    }
};
