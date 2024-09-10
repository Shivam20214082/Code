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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode* prev=head;
        ListNode* root=head->next;
        while(root!=NULL){
            int x=__gcd(prev->val,root->val);
            ListNode* temp=new ListNode(x);
            temp->next=root;
            prev->next=temp;
            prev=root;
            root=root->next;
        }
        return head;
    }
};