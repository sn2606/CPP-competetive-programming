// Given a string containing just the characters '(' and ')', find the 
// length of the longest valid (well-formed) parentheses substring.
// leetcode HARD!!

# include <iostream>
# include <algorithm>
# include <stack>
# include <vector>
using namespace std;

// high time and space complexity, can be optimized
class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s.size() <= 1){
            return 0;
        }
        
        int ans = 0, n = s.size(), t, sum = 0;
        stack <int> stck;
        vector <int> len;
        
        for(int i = 0; i < n; i++){
                        
            if(s[i] == '('){
                stck.push(s[i]);
                len.push_back(0);
                t = len.size() - 1;
            }else{
                if(!stck.empty()){
                    if(stck.top() == '('){
                        stck.pop();
                        if(len[t] == 0){
                            len[t] = 2;
                            while(t != 0 && len[t]){
                                t--;
                            }
                        }
                    }
                }else{
                    len.push_back(0);
                }
            }
            
            // for(int i : len){
            //     cout << i << "\n";
            // }
            // cout << "t = " << t << "\n";
            // cout << "\n";
        }
        
        for(int i : len){
            if(i == 0){
                sum = 0;
            }else{
                sum += i;
            }
            
            ans = sum > ans ? sum : ans;
        }
        
        
        return ans;
    }
};

// optimized solution by stack
class Solution2 {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};