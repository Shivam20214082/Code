class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHalf = reverseList(slow);
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf;
        
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        reverseList(secondHalfCopy);
        return true;
    }
};
