#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {

        stack<long long> st;

        int n = nums.size();

        vector<long long> ind(n,0);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();

            if(st.size()) ind[i] = st.top();

            else ind[i] = i;

            st.push(i);
        }

        long long i = 0;

        long long ans = 0;

        while(i<n)
        {
           if(ind[i]!=i)
           {
                ans+=(ind[i]-i)*nums[i];

                i = ind[i];
           }
           
           else
           {
                ans+=(n-1-i)*nums[i];

                break;
           }
        }

        return ans;
    }
};

