// 1. You are given a sorted array and a number.
// 2. You have to return ceil of the given number in the array.
// 3. Ceil is the smallest number which is just greater than or equal to given number.
// 4. If there is no ceil, print "There is no ceiling"

// Easy Problem
// Linear search if array given is not sorted
// Binary search if array given is sorted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> k;
    
    int ceil = INT_MAX;
    int flag = -1;
    
    for(int i = 0; i < n; i++){
        if(arr[i] >= k && arr[i] < ceil){
            ceil = arr[i];
            flag = 0;
        }
    }
    
    if(flag == -1){
        cout << "There is no ceiling";
    }else{
        cout << ceil;
    }
    
    return 0;
}
