#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string bin(string str){
        int num=stoi(str);
        string x="";
        while(num>0){
            if(num%2==0)x+='0';
            else x+='1';
            num/=2;
        }
        reverse(x.begin(),x.end());
        return x;
    }
    string convertDateToBinary(string date) {
        string ans="";
        // cout<<date.substr(5,2);
        ans+=bin(date.substr(0,4))+"-"+bin(date.substr(5,2))+'-'+bin(date.substr(8,2));
        return ans;

    }
};