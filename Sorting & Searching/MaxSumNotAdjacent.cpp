// 1. You are given N, an integer, representing number of elements in array
// 2. You are given N integer, representing contents of array.
// 3. Find and print the maximum sum possible for a set of non-adjacent 
// elements selected from the array such that its sum is maximum.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n, b;    
    cin >> n >> b;
    
    int including = b, excluding = 0, exclude_updated;
    
    for(int i = 1; i < n; i++){
        cin >> b;
        exclude_updated = max(including, excluding); // max sum found behind current number
        including = excluding + b; // can't add b to including bc can't be consecutive
        excluding = exclude_updated;
    }
    
    cout << max(including, excluding);
    
    return 0;
}
