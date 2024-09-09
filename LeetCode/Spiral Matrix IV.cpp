#include <bits/stdc++.h>

using namespace std;



struct ListNode {
     int val;
     ListNode *next;
       ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        // Define boundaries for the spiral
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        
        while (head != NULL) {
            // Fill the top row (left to right)
            for (int i = left; i <= right && head != NULL; ++i) {
                ans[top][i] = head->val;
                head = head->next;
            }
            top++;  // Move the top boundary down
            
            // Fill the right column (top to bottom)
            for (int i = top; i <= bottom && head != NULL; ++i) {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;  // Move the right boundary left
            
            // Fill the bottom row (right to left)
            for (int i = right; i >= left && head != NULL; --i) {
                ans[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;  // Move the bottom boundary up
            
            // Fill the left column (bottom to top)
            for (int i = bottom; i >= top && head != NULL; --i) {
                ans[i][left] = head->val;
                head = head->next;
            }
            left++;  // Move the left boundary right
        }
        
        return ans;
    }
};
