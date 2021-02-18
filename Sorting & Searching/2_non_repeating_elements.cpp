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
    
    sort(arr.begin(), arr.end());
    
    int flag = 1;
    
    for(int i = 0; i < n-1; i++){
        if(arr[i] == arr[i+1]){
            flag = 1;            
        }else if(arr[i] != arr[i+1] && flag == 0){
            cout << arr[i] << " ";
        }else{
            flag = 0;
        }
    }
    
    if(arr[n-1] != arr[n-2])
        cout << arr[n-1];
    
    return 0;
}
