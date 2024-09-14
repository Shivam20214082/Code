#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi = *max_element(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            if(nums[i]==maxi){
                while(i<nums.size() && nums[i++]==maxi)cnt++;

                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};