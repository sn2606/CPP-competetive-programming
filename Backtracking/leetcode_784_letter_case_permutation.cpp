// Given a string S, we can transform every letter individually 
// to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. 
// You can return the output in any order

# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    
    void permute(vector <string> &ans, string &s, int ind){
        
        if(ind == s.size()){
            ans.push_back(s);
            return;
        }
        
        if(isalpha(s[ind])){
            permute(ans, s, ind+1);
            // s[ind] = isupper(s[ind]) ? tolower(s[ind]) : toupper(s[ind]);
            s[ind] ^= 32; // trick for toggle case
            permute(ans, s, ind+1);
        }else{
            permute(ans, s, ind+1);
        }
        
    }
    
    vector<string> letterCasePermutation(string S) {
        vector <string> ans;        
        permute(ans, S, 0);
        return ans;        
    }
};