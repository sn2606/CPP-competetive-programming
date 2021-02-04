// There are many situations where we use integer values as index in array 
// to see presence or absence, we can use bit manipulations to optimize space in such problems.
// 1. Take as input lo and hi, two integer.
// 2. Take as input k, an integer.
// 3. You have to find which numbers from lo to hi are divisible by k and store
// that information in a new array of size (hi - lo) / 32 as discussed in this link
// https://www.geeksforgeeks.org/space-optimization-using-bit-manipulations/
// 4. Print the contents of storage array.
// 5. Retrieve from the storage array, which elements are divisible by k and print
// them.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Here is a space optimized which uses bit manipulation technique 
// that can be applied to problems mapping binary values in arrays.
// Size of int variable in 64-bit compiler is 4 bytes. 
// 1 byte is represented by 8 bit positions in memory. 
// So, an integer in memory is represented by 32 bit positions(4 Bytes).
// These 32 bit positions can be used instead of just one index to hash binary values.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int lo, hi;
    int k;
    
    cin >> lo >> hi;
    cin >> k;
    
    int s = (hi - lo + 31)/32;
    
    vector<int> arr(s, 0);
    
    int j = 0;
    
    for(int i = lo; i <= hi; i++){
        j = (i - lo);
        if(i % k == 0){
            arr[j/32] |= (1 << (j % 32));
        }
    }
    
    for(int i : arr){
        cout << i << " ";
    }
    
    cout << "\n";
    
    for(int i = lo; i <= hi; i++){
        j = (i - lo);
        if(arr[j/32] & (1 << (j % 32)))
            cout << i << " ";
    }
    
    return 0;
}