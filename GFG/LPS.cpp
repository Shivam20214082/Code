class Solution {
public:
    int lps(string str) {
        int n = str.size();
        vector<int> lpsArr(n, 0);
        int len = 0;
        
        for (int i = 1; i < n; i++) {
            while (len > 0 && str[i] != str[len]) {
                len = lpsArr[len - 1];
            }
            
            if (str[i] == str[len]) {
                len++;
            }
            
            lpsArr[i] = len;
        }
        
        return lpsArr[n - 1];
    }
};

