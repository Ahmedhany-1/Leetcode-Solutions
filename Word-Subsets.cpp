class Solution {  
public:  
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {  
        unordered_map<char, int> freq;  
          
        for (const auto &word : words2) {  
            unordered_map<char, int> tempFreq;  
            for (auto &c : word) {  
                tempFreq[c]++;  
            }  
            for (auto &[c, count] : tempFreq) {  
                freq[c] = max(freq[c], count);  
            }  
        }  

        vector<string> ans;  
        
        
        for (const auto &word : words1) {  
            unordered_map<char, int> freq2;  
            for (auto &c : word) {  
                freq2[c]++;  
            }  

            bool isUniversal = true;  
            for (auto &[c, count] : freq) {  
                if (freq2[c] < count) {  
                    isUniversal = false;  
                    break;  
                }  
            }  
            
            if (isUniversal) {  
                ans.emplace_back(word);  
            }  
        }  
        
        return ans;  
    }  
};