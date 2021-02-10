// 1. You are given an array of integers.
// 2. You have to print majority element of the array. Majority element is the element
// which occurs more than half of array size.
// 3. If there is no such element, print "NO Majority Element".


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin >> n;
    
    vector <int> arr(n);
    unordered_map <int, int> mapArr;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mapArr[arr[i]]++;
    }
    
    int flag = -1;
    int ans = 0;
    
    for(auto i : mapArr){
        // cout << i.first << " " << i.second << "\n";        
        
        if(i.second > n/2 && i.second > flag){
            ans = i.first;
            flag = i.second;
        }
    }
    
    if(flag != -1)
        cout << ans;
    else
        cout << "NO Majority Element";
    
    
    
    return 0;
}
