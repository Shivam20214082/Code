#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>ans;
        bool start=false;
        for(int i=0;i<height.size();i++){
            if(start){
               
                    ans.push_back(i);
            }
            if(height[i]>threshold)start=true;
            else start=false;
        }
        return ans;
    }
};