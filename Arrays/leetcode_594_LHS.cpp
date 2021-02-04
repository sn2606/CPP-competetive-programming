// We define a harmonious array as an array where the difference 
// between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest 
// harmonious subsequence among all its possible subsequences.
// A subsequence of array is a sequence that can be derived from 
// the array by deleting some or no elements without changing 
// the order of the remaining elements.



# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            
            if(freq.count(nums[i]+1))
                res = res > freq[nums[i]] + freq[nums[i]+1] ? res : freq[nums[i]] + freq[nums[i]+1];
            
            if(freq.count(nums[i]-1))
                res = res > freq[nums[i]] + freq[nums[i]-1] ? res : freq[nums[i]] + freq[nums[i]-1];     
            
        }        
        return res;        
    }
};