// There are several cards arranged in a row, and each card has an associated number of points 
// The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefixSum(n+1, 0);
        
        for(int i = 0; i < n; i++){
            prefixSum[i+1] = prefixSum[i] + cardPoints[i];
        }
        
        int res = 0;
        
        for(int i = 1, j = n-k; j <= n; i++,j++){
            int sum = prefixSum[n]-prefixSum[j]+prefixSum[i-1];
            res = sum > res? sum : res;            
        }
        
        return res;        
    }
};