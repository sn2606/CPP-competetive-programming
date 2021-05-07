// Given two strings word1 and word2, return the minimum number of steps
// required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

// approach -> delete the characters that are not common in both the strings
// basically find the length of the longest common subsequence = l
// length of string 1 = m
// length of string 2 = n
// answer = (m-l)+(n-l) -> because l will be the final attainable answer

# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> DP (m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    DP[i][j] = 1+DP[i-1][j-1];
                }else {
                    DP[i][j] = DP[i-1][j] > DP[i][j-1] ? DP[i-1][j] : DP[i][j-1];
                }
            }
        }
        
//         for(int i = 0; i <= m; i++){
//             for(int j = 0; j <= n; j++){
//                 cout << DP[i][j] << "   ";
//             }
//             cout << "\n";
//         }
        
//         cout << DP[m][n];
        
        return (m - DP[m][n] + n - DP[m][n]);
    }
};