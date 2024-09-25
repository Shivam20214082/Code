class TrieNode {
public:
    TrieNode* children[26];
    int count;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children[c - 'a'] == nullptr) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
                node->count++;
            }
        }
        
        vector<int> result;
        for (const string& word : words) {
            int score = 0;
            TrieNode* node = root;
            for (char c : word) {
                node = node->children[c - 'a'];
                score += node->count;
            }
            result.push_back(score);
        }
        
        return result;
    }
};
