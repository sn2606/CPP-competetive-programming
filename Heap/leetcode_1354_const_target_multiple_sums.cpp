// Given an array of integers target. From a starting array, A consisting of all 1's, 
// you may perform the following procedure :
// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
// You may repeat this procedure as many times as needed.
// Return True if it is possible to construct the target array from A otherwise return False.

# include <iostream>
# include <vector>
# include <queue>     // for priority queue
# include <algorithm>
# include <numeric>   // for accumulate
using namespace std;

// Space complexity: O(N) for pq
// We will have O(max(target)) number of loops (upper bound)
// C++ constructor will take O(N) time to build priority queue from vector (floyd's algo)
// O(logN) to pop()
// O(logN) to push()
// O(1) to top()
// total time complexity becoes O(max(targer)*logN)

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int64_t sum = accumulate(target.begin(), target.end(), (int64_t)0);  // range is large so we are using 64 bit integer
        priority_queue<int> pq(target.begin(), target.end());
        
        while(sum > 1 && pq.top() > sum/2) {
            int max = pq.top();
            pq.pop();
            
            sum -= max;
            
            if(sum == 0)            // sum - max = 0 means sum of remaining nums = 0 and since all are +ve, all nums = 0
                return false;
            else if(sum == 1)       // sum-max = 1 means sum of remaining nums = 1 ans since all are integers, there will only be the 1 => max-1 steps to reach max -> just keep adding and updating max
                return true;
            else
                pq.push(max % sum); // max will always be greater than sum of remaining elems
            
            sum += max % sum;       // new sum of all elements
            
        }
        
        return sum == target.size();
    }
};