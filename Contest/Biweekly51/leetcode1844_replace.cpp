// You are given a 0-indexed string s that has lowercase English letters in its even indices 
// and digits in its odd indices.
// There is a function shift(c, x), where c is a character and x is a digit, 
// that returns the xth character after c.
// For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.
// For every odd index i, you want to replace the digit s[i] with shift(s[i-1], s[i]).
// Return s after replacing all digits. It is guaranteed that shift(s[i-1], s[i]) will never exceed 'z'.

# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 1){
                s[i] = s[i-1] + ((int)(s[i] - '0'));
            }
        }
        return s;
    }
};