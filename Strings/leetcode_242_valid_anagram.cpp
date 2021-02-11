// Given two strings s and t , write a function to determine if t is an anagram of s.
// Easy problem

# include <iostream>
# include <algorithm>
# include <string>
using namespace std;

// Solutions
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        int arr[26] = {0};
        
        for(int i = 0; i < s.size(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(arr[i])
                return false;
        }
        
        return true;        
    }

    bool isAnagram2(string s, string t) {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s==t){
            return true;
        }else{
            return false;
        }        
    }
};