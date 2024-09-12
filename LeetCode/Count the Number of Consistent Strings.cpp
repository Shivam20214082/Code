#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>v(26,0);
        for(char c:allowed){
            v[c-'a']=1;
        }
        int ans=0;

        for(string str:words){
            bool n=true;
            for(char c:str){
                if(v[c-'a']==0){
                    n=false;
                    break;
                }
            }
            if(n)ans++;
        }
        return ans;
    }
};