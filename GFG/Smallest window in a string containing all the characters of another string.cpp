class Solution {
public:
    string smallestWindow(string s, string p) {
        if (s.size() < p.size()) return "-1";
        
        // Create frequency maps for p and the current window
        vector<int> pCount(26, 0), windowCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        
        int requiredChars = p.size();
        int minLen = INT_MAX;
        int minStart = 0;
        string result = "";
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // Expand the window to the right
            char c = s[right];
            windowCount[c - 'a']++;
            if (pCount[c - 'a'] > 0 && windowCount[c - 'a'] <= pCount[c - 'a']) {
                requiredChars--;
            }
            
            // Shrink the window from the left
            while (requiredChars == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                char c = s[left];
                windowCount[c - 'a']--;
                if (pCount[c - 'a'] > 0 && windowCount[c - 'a'] < pCount[c - 'a']) {
                    requiredChars++;
                }
                left++;
            }
        }
        
        // Return the smallest window
        if (minLen == INT_MAX) return "-1";
        return s.substr(minStart, minLen);
    }
};
