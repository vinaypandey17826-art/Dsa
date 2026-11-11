class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        
        if (s.length() < totalLen) return result;
        
        // Frequency map of all words in the input array
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        // Iterate only for the length of one word to cover all possible starting offsets
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seenWords;
            int count = 0;
            
            while (right + wordLen <= s.length()) {
                string sub = s.substr(right, wordLen);
                right += wordLen;
                
                // If the word is valid, add it to the window
                if (wordCount.count(sub)) {
                    seenWords[sub]++;
                    count++;
                    
                    // If a word appears more times than allowed, shrink from the left
                    while (seenWords[sub] > wordCount[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        seenWords[leftSub]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // If we've matched all words, record the starting index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Not a valid word, reset the window
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};