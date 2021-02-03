// Given an array of positive integers, we need to make that array a palindrome
// The only allowed operation is merging
// Merging two adjacent elements means replacing them with their sum


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
    
    vector <int> v(n);
    
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int count = 0;
    
    for(i = 0, j = n-1; i != j;){
        
        if(v[i] == v[j]){
            i++;
            j--;
            continue;
        }else{
            v[i+1] += v[i];
            i++;
            count++;            
        }        
    }
    
    cout << count;
    
    return 0;
}
