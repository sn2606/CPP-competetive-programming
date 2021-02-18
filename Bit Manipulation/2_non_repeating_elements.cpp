// 1. You are given an array of integers. All the array elements are occuring even 
// number of times, except two.
// 2. Those two elements are occuring only once.
// 3. You have to print those 2 numbers. 

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
    
    vector <int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x = 0;
    
    for(int i = 0; i < n; i++){
        x ^= arr[i];
    }
    
    int bit = x & ~(x - 1);
    
    vector <int> sets(n);
    int num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++){
        if(bit & arr[i]){
            num1 ^= arr[i];
        }else{
            num2 ^= arr[i];
        }
    }
    
    cout << num1 << " " << num2;
    
    return 0;
}
