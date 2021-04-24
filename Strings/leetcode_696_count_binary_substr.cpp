// Give a string s, count the number of non-empty (contiguous) substrings that have the same number 
// of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.

# include <iostream>
# include <string>
using namespace std;


class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0, ones = 0, zeros = 0, n = s.size();
        
        if(n <= 1){
            return 0;
        }
        
        s[0] == '0' ? zeros++ : ones++;
        
        // cout << zeros << " " << ones;
        
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                s[i] == '0' ? zeros++ : ones++;
            }else{
                result += (ones < zeros) ? ones : zeros;
                s[i] == '0' ? zeros = 1 : ones = 1;
            }
        }
        
        result += (ones < zeros) ? ones : zeros;        

        return result;
        
    }
};