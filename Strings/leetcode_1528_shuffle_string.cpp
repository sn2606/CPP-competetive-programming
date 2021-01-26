// Given a string s and an integer array indices of the same length.
// The string s will be shuffled such that the character 
// at the ith position moves to indices[i] in the shuffled string.
// Return the shuffled string.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i = 0;
        
        while(i < indices.size()){
            if(indices[i] == i){
                i++;
            }
            else{
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        
        return s;
        
    }
};