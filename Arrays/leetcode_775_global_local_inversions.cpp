// We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.
// The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
// The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
// Return true if and only if the number of global inversions is equal to the number of local inversions.

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        
        for(int i = 0; i < A.size(); i++){
            if(abs(A[i] - i) > 1){
                return false;
            }
        }
        
        return true;        
    }
};