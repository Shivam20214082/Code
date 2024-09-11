#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start || goal){
            if(start%2!=goal %2)ans++;
            start/=2;
            goal/=2;
        }
        while(start){
            ans++;
            start/=2;
        }
        while(goal){
            ans++;
            goal/=2;
        }
        return ans;
    }
};