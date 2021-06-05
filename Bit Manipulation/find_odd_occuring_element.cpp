// Given an array of positive integers. All numbers occur an even number of times except 
// one number which occurs an odd number of times. Find the number in O(n) time & constant space.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin >> n;
    vector<int>arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x = 0;
    
    for(int i = 0; i < n; i++){
        x ^= arr[i];
    }
    
    cout << x;
    
    return 0;
}
