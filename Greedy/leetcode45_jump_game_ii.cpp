// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

# include <iostream>
# include <vector>
using namespace std;

// O(V + E) solution -> BFS-y problem. V = number of elements in the array
// the graph can be seen as: each element of the array is a node and all the jump-reachable
// nodes are connected to the node
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n-1; ){
            int m = n;
            int mind = 0;
            if(i + nums[i] >= n-1){
                return count+1;
            }
            for(int j = i+1; j <= i+nums[i] && j < n; j++){
               if(n-1 - j - nums[j] < m){
                   m = n-1 - j - nums[j];
                   mind = j;
               }
            }
            i = n-1 < mind ? n-1 : mind;
            count++;
        }
        
        return count;
    }
};