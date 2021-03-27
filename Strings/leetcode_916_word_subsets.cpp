// We are given two arrays A and B of words.  Each word is a string of lowercase letters.
// Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  
// For example, "wrr" is a subset of "warrior", but is not a subset of "world".
// Now say a word a from A is universal if for every b in B, b is a subset of a. 
// Return a list of all universal words in A.  You can return the words in any order.

# include <iostream>
# include <vector>
# include <string>
using namespace std;

// O(A + B) where A = no. of characters in A and B = no. of characters in B
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int alph[26] = {0};
        int wc[26] = {0};
        
        for(string b : B) {
            for(char c : b){
                wc[c-'a']++;
            }
            
            for(int i = 0; i < 26; i++) {
                alph[i] = wc[i] > alph[i] ? wc[i] : alph[i];
                wc[i] = 0;
            }
        }
                
        vector <string> ans;
        
        for(string a : A) {
            for(char c : a){
                wc[c-'a']++;
            }
            
            int flag = 1;
            
            for(int i = 0; i < 26; i++) {
                if(alph[i] > wc[i]){
                    flag = 0;
                }
                wc[i] = 0;
            }
            
            if(flag == 1){
                ans.push_back(a);
            }
        }
        
        
        return ans;
    }
};