#include <vector>
#include <string>
#include <sstream>  
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> word_count;
        
        // Helper lambda function to split a string into words and count frequencies
        auto countWords = [&](const string &sentence) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                word_count[word]++;
            }
        };
        
        // Count words in both sentences
        countWords(s1);
        countWords(s2);
        
        // Find the uncommon words (those that appear exactly once)
        vector<string> result;
        for (const auto &entry : word_count) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
