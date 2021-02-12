// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
// For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

// Given a string n that represents a positive decimal integer, return the minimum number of positive 
// deci-binary numbers needed so that they sum up to n.

# include <iostream>
# include <string>
using namespace std;

// The answer is equal to the max digit
// Since we are adding numbers which contain only 0 or 1 as digits
// and the max digit in given number is 9
// there is no case of carry-over
class Solution {
public:
    int minPartitions(string n) {
        int res = 1;
        
        for(int i = 0; i < n.size(); i++){
            
            if(n[i]-'0' > res)
                res = n[i]-'0';            
        }
        
        return res;  
        
    }
};