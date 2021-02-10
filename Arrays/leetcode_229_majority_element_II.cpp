// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Follow-up: Could you solve the problem in linear time and in O(1) space?

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// Boyer-Moore voting algorithm with a modification
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // there can be at most 2 elements strictly greater than
        // |_n/3_|
        int x = -1, y = -1, i;
        int countx = 0, county = 0;
        
        for(i = 0; i < nums.size(); i++){
            if(x == nums[i]){
                countx++;
            }else if(y == nums[i]){
                county++;
            }else if(!countx){
                countx = 1;
                x = nums[i];
            }else if(!county){
                county = 1;
                y = nums[i];
            }else{
                countx--;
                county--;
            }          
        }
        
        countx = 0;
        county = 0;
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == x){
                countx++;
            }else if(nums[i] == y){
                county++;
            }
        }
        
        vector <int> ans;
        
        if(countx > nums.size()/3)
            ans.push_back(x);
        
        if(county > nums.size()/3)
            ans.push_back(y);
        
        return ans;
        
    }
};