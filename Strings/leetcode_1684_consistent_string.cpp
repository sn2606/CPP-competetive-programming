// You are given a string allowed consisting of distinct characters 
// and an array of strings words. A string is consistent if all characters 
// in the string appear in the string allowed.
// Return the number of consistent strings in the array words.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int hash[26] = {0};
        int flag = 1;
        int result = 0;
        
        for(auto c : allowed){
            hash[(c % 26)]++;
        }
        
        for(int i = 0; i < words.size(); i++){
            
            flag = 1;
            
            for(auto c : words[i]){
                if(!hash[(c % 26)]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                result++;
            }
        }
        
        return result;        
    }
};