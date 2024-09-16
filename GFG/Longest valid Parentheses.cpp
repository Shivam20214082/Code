#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxLength(string& str) {
        int n = str.size();
        int open = 0, close = 0, maxLen = 0;

        // Left to right traversal
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') open++;
            else close++;

            if (open == close) {
                maxLen = max(maxLen, 2 * close);  
            } else if (close > open) {
                open = close = 0; 
            }
        }


        open = close = 0;

        // Right to left traversal
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '(') open++;
            else close++;

            if (open == close) {
                maxLen = max(maxLen, 2 * open);  
            } else if (open > close) {
                open = close = 0;  
            }
        }

        return maxLen;
    }
};