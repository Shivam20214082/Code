#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool checkPath(ListNode* head, TreeNode* root) {
        if (!head) return true; // End of linked list
        if (!root) return false; // End of tree
        if (root->val != head->val) return false; // Values don't match
        return checkPath(head->next, root->left) || checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // End of tree
        return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to create a binary tree node
TreeNode* newTreeNode(int value) {
    TreeNode* node = new TreeNode(value);
    return node;
}

int main() {
    // Create linked list: 4 -> 2 -> 8
    vector<int> listValues = {4, 2, 8};
    ListNode* head = createLinkedList(listValues);

    // Create binary tree:
    //         1
    //        / \
    //       4   4
    //      /   / \
    //     2   2   6
    //    /   /
    //   1   8
    //        \
    //         1
    TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(4);
    root->right = newTreeNode(4);
    root->left->left = newTreeNode(2);
    root->left->left->left = newTreeNode(1);
    root->right->left = newTreeNode(2);
    root->right->right = newTreeNode(6);
    root->right->left->left = newTreeNode(8);
    root->right->left->left->right = newTreeNode(1);

    Solution solution;
    bool result = solution.isSubPath(head, root);

    cout << (result ? "True" : "False") << endl;

    return 0;
}
