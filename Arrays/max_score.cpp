// 1. Take as input N, row * col of a 2-d array.
// 2. Take N * N integers as input
// 3. Make a selection of elements from the 2-d array, by selecting an element from
// each row. The element selected from ith row should be smaller than element
// selected from i + 1th row. Out of all the possible selections, chose the
// selection of elements which has maximum sum of elements.
// 4. Print the maximum sum thus found.
// Greedy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, i, j;
    
    cin >> n;
    
    vector<vector<int>>arr(n, vector<int>(n));
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end());
    }
    
    // for(i = 0; i < n; i++){
    //     for(j = 0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    int res = 0, max = arr[n-1][n-1], flag = 1;
    
    res += max;
    for(i = n-2; i >= 0; i--){
        flag = 0;
        for(j = n-1; j >= 0; j--){
            if(arr[i][j] < max){
                flag = 1;
                max = arr[i][j];
                res += max;
                break;
            }            
        }
        
        if(!flag){
            cout << -1;
            return 0;
        }
    }
    
    cout << res;   
    
    return 0;
}