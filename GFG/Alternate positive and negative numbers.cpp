#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> p;
        vector<int>q;
        for(int i:arr){
            if(i>=0)p.push_back(i);
            else q.push_back(i);
        }
        int i=0,x=0;
        while(x<p.size() && x<q.size()){
            arr[i]=p[x];
            arr[i+1]=q[x];
            x++;
            i+=2;
        }
        while(x<p.size()){
            arr[i]=p[x];
            x++;
            i++;
        }
        while(x<q.size()){
            arr[i]=q[x];
            x++;
            i++;
        }
        
        
    }
};