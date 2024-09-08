#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* root = head;
        while (root != NULL) {
            n++;
            root = root->next;
        }
        
        int partSize = n / k;
        int extraNodes = n % k;
        
        vector<ListNode*> ans(k, nullptr);
        root = head;
        for (int i = 0; i < k && root != NULL; i++) {
            ans[i] = root;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;
            
            for (int j = 1; j < currentPartSize; j++) {
                if (root != NULL) root = root->next;
            }
            
            if (root != NULL) {
                ListNode* nextPart = root->next;
                root->next = NULL;
                root = nextPart;
            }
        }
        
        return ans;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to print the result in a nested list format
void printResult(const vector<ListNode*>& result) {
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == nullptr) {
            cout << "[] ";
        } else {
            ListNode* current = result[i];
            cout << "[";
            while (current != nullptr) {
                cout << current->val;
                if (current->next != nullptr) cout << ",";
                current = current->next;
            }
            cout << "] ";
        }
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> vals1 = {1, 2, 3};
    ListNode* head1 = createLinkedList(vals1);
    int k1 = 5;
    vector<ListNode*> result1 = solution.splitListToParts(head1, k1);
    cout << "Result for test case 1:" << endl;
    printResult(result1);
    
    // Test case 2
    vector<int> vals2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head2 = createLinkedList(vals2);
    int k2 = 3;
    vector<ListNode*> result2 = solution.splitListToParts(head2, k2);
    cout << "Result for test case 2:" << endl;
    printResult(result2);
    
    return 0;
}
