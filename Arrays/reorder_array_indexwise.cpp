// 1. Take as input N, number of elements in array.
// 2. Take N inputs - Ai - as elements of array A.
// 3. Take N inputs - Idxi - as elements of array Idx.
// 4. The Idx array represents that A array contains Idxith element at its ith
// position. E.G.
// A -> 50 40 70 60 90
// Idx -> 3 0 4 1 2
// The above data suggests A has its 3th element at 0th index, 0th element at 1 index,
// 4th element at 2 index, 1th element at 3 index and 2th element at 4th index.
// 5. Sort A, such that each element occurs where it should i.e. first at first spot,
// second at second and so on.
// 6. Print the sorted array.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, i;
    
    cin >> n;
    
    vector<int> nums(n), idx(n);
    
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    for(i = 0; i < n; i++){
        cin >> idx[i];
    }
    
    for(i = 0; i < n; i++){
        while(idx[i] != i){
            swap(nums[i], nums[idx[i]]);
            swap(idx[i], idx[idx[i]]);
        }
    }
    
    for(int i: nums){
        cout << i << " ";
    }    
    
    return 0;
}
