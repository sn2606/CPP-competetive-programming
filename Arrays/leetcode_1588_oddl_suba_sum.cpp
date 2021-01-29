// Given an array of positive integers arr, 
// calculate the sum of all possible odd-length subarrays.
// A subarray is a contiguous subsequence of the array.
// Return the sum of all odd-length subarrays of arr.

#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, prefix = 0, n = arr.size(), i, j;
        
        vector<int>p;
        
        for(i = 0; i < n; i++){
            prefix += arr[i];
            p.push_back(prefix);
        }
        
        for(i = 0; i < n; i++){
            if(i%2 == 0){
                res += p[i];
                for(j = 1; j < i; j += 2){
                    res += (p[i] - p[j]);
                }
            }else{
                for(j = 0; j < i; j += 2){
                    res += (p[i] - p[j]);
                }
            }
        }
        
        return res;        
    }
};