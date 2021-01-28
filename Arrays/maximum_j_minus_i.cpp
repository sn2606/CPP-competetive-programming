// 1. You are given an array of integers. 
// 2. Let i and j be the array indices. 
// 3. You have to print the maximum difference between j and i, such that arr[j]>arr[i].
// 4. If there is no such j and i for which this condition is true, then print -1.
// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/


#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i, j;
    
    cin >> n;
    
    if(n <= 1){
        cout << -1;
        return 0;
    }
    
    vector <pair <int, int>> arr;
    pair <int, int> p;
        
    for(i = 0; i < n; i++){
        cin >> j;
        p.first = j;
        p.second = i;
        
        arr.push_back(p);
    }
    
    vector <pair <int, int>> max(n);
    max[n-1].first = arr[n-1].first;
    max[n-1].second = arr[n-1].second;
    
    for(i = n-2; i >= 0; i--){
        if(max[i+1].first < arr[i].first){
            max[i].first = arr[i].first;
            max[i].second = arr[i].second;
        }else{
            max[i].first = max[i+1].first;
            max[i].second = max[i+1].second;
        }
    }
    
    // for(auto r: arr)
    //     cout << r.first << " " << r.second << "\n";
    
    
    // max will be a monotonously decreasing array
    
    int ans = 0;
    int low, high, mid, ind;
    
    for(i = 0; i < n; i++){
        low = i+1; 
        high = n-1;
        ind = i;
        
        while(low <= high){
            mid = (low + high)/2;
            
            if(arr[i].first <= max[mid].first){
                ind = mid > ind ? mid : ind;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        ans = (ind - i) > ans ? (ind - i) : ans;
    }
    
    if(ans <= 0) ans = -1;
    
    cout << ans;
    
    return 0;
}
