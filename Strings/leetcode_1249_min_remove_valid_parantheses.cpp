// Given a string s of '(' , ')' and lowercase English characters. 

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
// so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.

# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        vector <int> ditch;
        string res = "";
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '(') {
                count++;
            }
            
            if(s[i] == ')') {
                if(count > 0){
                    count--;
                }else {
                    ditch.push_back(i);
                }
            }
        }
        
        // cout << count << "\n";
        
        int j = ditch.size()-1;
        
        for(int i = n-1; i >= 0; i--) {
            
            if(j >= 0 && ditch[j] == i) {
                j--;
            }else {
                if(s[i] == '(' && count > 0) {
                    count--;
                    // cout << i << count << "\n";
                }else {
                    res += s[i];
                }
            }
            
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};