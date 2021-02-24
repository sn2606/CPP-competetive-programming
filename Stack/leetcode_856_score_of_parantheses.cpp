// Given a balanced parentheses string S, compute the score of the string 
// based on the following rule:
// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.



# include <iostream>
# include <string>
# include <stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack <int> s;
        s.push(0);
        
        for(char c : S){
            if(c == '('){
                s.push(0);
            }else{
                if(!s.empty()){
                    int t = s.top();
                    int val = 0;
                    s.pop();
                    if(t == 0){
                        val = 1;
                    }else{
                        val = 2*t;
                    }
                    
                    s.top() += val;
                }
            }
        }
        
        return s.top();
        
    }
};