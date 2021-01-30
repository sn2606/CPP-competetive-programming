// We are given an array A of positive integers, 
// and two positive integers L and R (L <= R).
// Return the number of (contiguous, non-empty) subarrays 
// such that the value of the maximum array element 
// in that subarray is at least L and at most R.

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, l, h, i, res = 0;
    cin >> n;
    
    vector <int> a(n);
    
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cin >> l >> h;
    
//  Using Inclusion Exclusion Principle
//     int maxg = INT_MIN;
//     int maxl = INT_MIN;
    
//     //res = n*(n+1)/2;
//     int len = n;
    
//     for(i = 0; i < n; i++){
//         if(a[i] > maxg){
//             maxg = a[i];
//         }
//         if(a[i] > maxl){
//             maxl = a[i];
            
//             if(maxl < l || maxl > h){
//                 if(maxl < maxg){
//                     res -= (len-(i-(n-len)))*((i - (n - len))+1);
//                     // res -= (n-i)*(i+1);                    
//                 }else{
//                     res -= (n-i)*(i+1);
//                 }
//                 len = n - (i+1);
//                 maxl = INT_MIN;
//             }else{
//                 if(maxl < maxg)
//                     res += (len-(i-(n-len)))*((i - (n - len))+1);
//                 else
//                     res += (n-i)*(i+1);
//             }
//         }else{
//                 res += (len-(i-(n-len)));//*((i - (n - len))+1);
//                 // res += (n-i)*(i+1);
//         }
//     }
    
    int L = -1, R = -1;
    
    for(i = 0; i < n; i++){
        if(a[i] > h)
            L = i;
        
        if(a[i] >= l)
            R = i;
        
        res += (R - L);
        
    }
    
    cout << res;
    
    
    return 0;
}
