#include <bits/stdc++.h>

using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base case: if the node is null, return
        if (node == NULL) return;

        // Swap the left and right children
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively call mirror for left and right children
        mirror(node->left);
        mirror(node->right);
    }
};
