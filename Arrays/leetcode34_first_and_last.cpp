// Given an array of integers nums sorted in ascending order, 
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// Follow up: Could you write an algorithm with O(log n) runtime complexity?

# import <iostream>
# import <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res = {-1, -1};
        int n = nums.size();
        
        if(n == 0)
            return res;
        
        int low = 0, high = n-1;
        int mid = (low+high)/2;
        
        // for finding the lower bound
        while(low < high){
            mid = (low + high)/2;
            if(nums[mid] < target)
                low = mid+1;
            if(nums[mid] >= target)
                high = mid;
        }
        
        if(nums[low] == target)
            res[0] = low;
        else if(low + 1 >= n-1 || nums[low+1] != nums[low])
            return res;
        
        // for finding the upper bound
        high = n-1;
        mid = ((low + high)/2) + 1;
        
        while(low < high){
            mid = ((low + high)/2) + 1;
            // cout << mid << "\n";
            if(nums[mid] > target)
                high = mid - 1;
            if(nums[mid] <= target)
                low = mid;
        }
        
        if(nums[high] == target)
            res[1] = high;
        
        return res;
    }
};

