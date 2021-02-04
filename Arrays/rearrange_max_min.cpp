// 1. You are given sorted array of positive numbers. 
// You have to rearrange and print the array elements in maximum-minimum form. 
// 2. Maximum-minimum form means first element is maximum of the array, 
// followed by minimum of array, followed by second max of the array, 
// followed by second min and so on.
// 3. Allowed time complexity is O(n) and allowed space complexity is O(1).


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
    int arr[n];
    
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int max_element = arr[n-1] + 1, max_index = n-1, min_index = 0;
    
    // multiplication-modular encoding
    for(i = 0; i < n; i++){
        if(i%2 == 0){
            arr[i] += (arr[max_index] % max_element)*max_element;
            max_index--;
        }else{
            arr[i] += (arr[min_index] % max_element)*max_element;
            min_index++;
        }
    }
    
    // multiplication-modular decoding
    for(i = 0; i < n; i++){
        arr[i] /= max_element;
        cout << arr[i] << " ";
    }
    
    return 0;
}