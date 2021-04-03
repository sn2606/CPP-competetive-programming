// Given a string containing just the characters '(' and ')', find the
// length of the longest valid (well-formed) parentheses substring.
// leetcode HARD!!

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// high time complexity, can be optimized
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        if (s.size() <= 1)
        {
            return 0;
        }

        int ans = 0, n = s.size(), t, sum = 0;
        // stack <int> stck;
        vector<int> len;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == '(')
            {
                // stck.push(s[i]);
                len.push_back(0);
                t = len.size() - 1;
            }
            else
            {
                if (len.size() != 0)
                {
                    if (len[t] == 0)
                    {
                        len[t] = 2;
                        while (t != 0 && len[t] != -1 && len[t])
                        {
                            t--;
                        }
                    }
                    else
                    {
                        len.push_back(-1);
                        t = len.size() - 1;
                    }
                }
                else
                {
                    len.push_back(-1);
                    t = len.size() - 1;
                }
            }

            // for(int i : len){
            //     cout << i << "\n";
            // }
            // cout << "t = " << t << "\n";
            // cout << "\n";
        }

        for (int i : len)
        {
            if (i == 0 || i == -1)
            {
                sum = 0;
            }
            else
            {
                sum += i;
            }

            ans = sum > ans ? sum : ans;
        }

        return ans;
    }
};

// optimized solution by stack
class Solution2
{
public:
    int longestValidParentheses(string s)
    {
        if (s.length() <= 1)
            return 0;
        int curMax = 0;
        vector<int> longest(s.size(), 0);
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    longest[i] = (i - 2) >= 0 ? (longest[i - 2] + 2) : 2;
                    curMax = max(longest[i], curMax);
                }
                else
                { // if s[i-1] == ')', combine the previous length.
                    if (i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
                    {
                        longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
                        curMax = max(longest[i], curMax);
                    }
                }
            }
            //else if s[i] == '(', skip it, because longest[i] must be 0
        }
        return curMax;
    }
};