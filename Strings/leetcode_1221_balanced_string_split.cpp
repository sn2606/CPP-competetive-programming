// Given a balanced string str of size N with an equal number of L and R, 
// the task is to find a maximum number X, such that 
// a given string can be partitioned into X balanced substring. 
// A string called to be balanced if the number of ‘L’s in the string equals the number of ‘R’s.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
        
        for(auto c : s){
            if(c == 'L'){
                cnt++;
            }else{
                cnt--;
            }
            
            if(!cnt){
                res++;
            }
        }
        
        return res;
    }
};