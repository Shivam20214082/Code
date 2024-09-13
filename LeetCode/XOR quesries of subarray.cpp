#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> v(n); 
        int ans = 0;

        // Create prefix XOR array
        for (int i = 0; i < n; i++) {
            ans ^= arr[i];
            v[i] = ans;
        }

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            // If l == 0, just use v[r], else use the XOR of v[r] and v[l-1]
            if (l == 0) res.push_back(v[r]);
            else res.push_back(v[r] ^ v[l - 1]);
        }

        return res;
    }
};
