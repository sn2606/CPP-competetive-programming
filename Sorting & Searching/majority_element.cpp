// 1. You are given an array of integers.
// 2. You have to print majority element of the array. Majority element is the element
// which occurs more than half of array size.
// 3. If there is no such element, print "NO Majority Element".


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
    
    int flag = -1;
    int ans = 0;
    int count = 0;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < (n-1); i++){
        if(arr[i] == arr[i+1]){
            count++;
            //If we are at last iteration, then the last element may be missed
            // if we dont increment count by 2           
            if(i == n-2){
                count++;
            }
        }
        
        if(arr[i] != arr[i+1]){
            count++;
        }
        
        if(count > n/2){
            ans = arr[i];
            flag = 0;
            break;
        }
        
        if(count <= n/2 && arr[i] != arr[i+1]){
            count = 0;
        }
    }
    
    if(flag == -1){
        cout << "NO Majority Element";
    }else{
        cout << ans;
    }   
    
    return 0;
}
