// A sequence of numbers is called arithmetic if it consists of at least three elements and 
// if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequences:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9

// The following sequence is not arithmetic.
// 1, 1, 2, 5, 7
 
// A zero-indexed array A consisting of N numbers is given. 
// A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

// A slice (P, Q) of the array A is called arithmetic if the sequence:
// A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

// The function should return the number of arithmetic slices in the array A.

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        // This vector will track difference between consecutive integers in the vector A
        vector <int> diff;
        int res = 0;
        int n = A.size();
        
        for(int i = 1; i < n; i++){
            diff.push_back(A[i] - A[i-1]);
        }
        
        // for(int i : diff) {
        //     cout << i << " ";
        // }
        
        int i = 0, j = 0;
        
        while(i < n-1 && j < n-1) {
            // every number in diff corresponds to difference btn consecutive elements
            // i.e. initial length of arithmetic sequence is 2
            int L = 2;
            for(j = i+1; j < n-1; j++){
                if(diff[j] == diff[i]) {
                    L++;
                }else {
                    if(L >= 3){
                        res += ((L - 1)*(L - 2)/2);
                    }
                    i = j; // Move both pointers to j's place for eveluation of remaining array
                    break;
                }
            }
            
            // When j reaches the last element of diff, the else if(L >= 3) is never evaluated
            // so we need to take care of that
            if(j == n-1 && L >= 3){
                res += ((L - 1)*(L - 2)/2);
            }
        }

        // Note:
        // (L-1)*(L-1)/2 comes from -> 
        // how many subsequences of length greater than or equal to 3
        // are there in an array of length L?
        // there are (L - k + 1) subsequences of length k
        // SUMMATION(L - k + 1) where k varies from 3 to L
        // Which after solving gives (L-1)*(L-2)/2
        
        return res;
        
    }
};

// DP Solution