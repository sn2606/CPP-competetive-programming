// https://www.geeksforgeeks.org/max-sum-of-m-non-overlapping-subarrays-of-size-k/
// In a given array nums of positive integers, 
// find three non-overlapping subarrays with maximum sum.
// Each subarray will be of size k, 
// and we want to maximize the sum of all 3*k entries.
// Return the result as a list of indices representing 
// the starting position of each interval (0-indexed). 
// If there are multiple answers, return the lexicographically smallest one.
// OR
// 1. You are given an array of integers. 
// 2. You are given another integer K, which represents size of subarrays.
// 3. You have to print the maximum sum possible of 3 K sized non overlapping subarrays.
// Both combined solutions:-

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, i, k;
    
    cin >> n;
    
    int arr[n];
    
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> k;
    
    if(n < 3*k){
        cout << -1;
        return 0;
    }
    
    int subs[n-k+1];
    int s = 0;
    
    for(i = 0; i < k; i++){
        s += arr[i];
    }
    
    subs[0] = s;
    
    for(i = 1; i < n-k+1; i++){
        s = s - arr[i-1] + arr[i+k-1];
        // cout << s << "\n";
        subs[i] = s;
    }
    
    // for(auto c : subs)
    //     cout << c << " ";
    
    // int p, q;
    int max = INT_MIN;
    // vector <int> ans(3);
    int posr[n-k+1], posl[n-k+1];
        
    posl[0] = 0;
    posr[n-k] = n-k;
    
    for(i = 1; i < n-k+1; i++){
        posl[i] = subs[i] > subs[posl[i-1]] ? i : posl[i-1];
    }
    
    for(i = n-k-1; i >= 0; i--){
        posr[i] = subs[i] >= subs[posr[i+1]] ? i : posr[i+1];
    }
    
    for(i = k; i <= n-2*k; i++){
        int l = posl[i-k], r = posr[i+k];
        s = subs[l] + subs[i] + subs[r];
        
        if(s > max){
            max = s;
            // ans = {l, i, r};
        }
        
    }
    
    // for(auto c: ans){
    //     cout << c << " ";
    // }
    cout << max;
        
    return 0;
}

