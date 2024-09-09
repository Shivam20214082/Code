#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int i = 0;
        
        while (i <= r) {
            if (arr[i] == 0) {
                swap(arr[i], arr[l]);
                l++;
                i++;
            } 
            else if (arr[i] == 2) {
                swap(arr[i], arr[r]);
                r--; 
            } 
            else {
                i++; 
            }
        }
    }
};
