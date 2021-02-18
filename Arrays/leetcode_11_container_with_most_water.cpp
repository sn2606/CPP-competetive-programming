// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
// Find two lines, which, together with the x-axis forms a container, such that the container contains 
// the most water.
// Notice that you may not slant the container.

# include <stdio.h>
# include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int res = 0;
        
        while(i < j){
            int h = height[i] > height[j] ? height[j] : height[i];
            res = res > (h*(j-i)) ? res : (h*(j-i));
            
            while(height[i] <= h && i < j)
                i++;
            while(height[j] <= h && i < j)
                j--;
        }
        
        return res;
        
    }
};