// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector <vector <int>> knap(m+1, vector<int>(n+1, 0));
        int res = 0;
        int nz, no;
        
        for(string s : strs) {
            nz = 0, no = 0;
            for(char c : s) {
                if(c == '0'){
                    nz++;
                }else{
                    no++;
                }
            }
            
            for(int i = m; i >= nz; i--){
                for(int j = n; j >= no; j--){
                    knap[i][j] = max(knap[i][j], knap[i-nz][j-no] + 1);
                }
            }
            
        }
        
        return knap[m][n];        
    }
};