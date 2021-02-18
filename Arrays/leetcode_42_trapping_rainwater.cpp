// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.
// LeetCode Hard problem

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, int right = n-1;
        int maxLeft = 0, maxRight = 0;
        int sum = 0;
        
        while(left <= right) {
            if(A[left] <= A[right]) {
                if(A[left] >= maxLeft) {
                    maxLeft = A[left];
                } else {
                    sum += maxLeft - A[left];
                }
                left++;
            } else {
                if(A[right] >= maxRight) {
                    maxRight = A[right];
                } else {
                    sum += maxRight - A[right];
                }
                right--;
            }
        }
        return sum;
    }

};