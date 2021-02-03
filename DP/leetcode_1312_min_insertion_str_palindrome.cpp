// Give minimum insertion steps to make the string a palindrome
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.
// Hard, Dynamic Programming, Memoization

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Solution using memoization
// Space complexity = O(N^2)
// Time complexity  = O(N^2) -> visits all matrix cells at least once

class Solution{
public:
    vector<vector<int>> mem;

    int memoize(string s, int i, int j){
        if(i >= j)
            return 0;                   // Base case. i increases from one side and j decreases from other

        if(mem[i][j] != -1)
            return mem[i][j];           // If it is already calculated for (i, j), then return that

        mem[i][j] = (s[i] == s[j]) ? memoize(s, i+1, j-1) : min(memoize(s, i, j-1), memoize(s, i+1, j));
        return mem[i][j];
    }


    int minInsertions(string s){

        mem.resize(s.size(), vector <int>(s.size(), -1));
        return memoize(s, 0, s.size()-1);
    }
};

// Bottom - Up approach
// Space complexity can be reduced to 

class Solution2{
public:
    int minInsertions2(string s){
        vector <int> mem(s.size(), 0);

        int prev, temp;

        for(int i = s.size()-2; i >= 0; i--){

            prev = 0;                       // Stores the value at mem[i+1][j-1]

            for(int j = i; j < s.size(); j++){
                temp = mem[j];
                mem[j] = (s[i] == s[j]) ? prev : 1 + min(mem[j], mem[j-1]);
                prev = temp;
            }

        }

        return mem[s.size() - 1];
    }
};