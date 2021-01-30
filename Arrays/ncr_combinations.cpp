// 1. Take as input N, number of elements in array.
// 2. Take N inputs - Ai - as elements of array A.
// 3. Take as input R, number of elements to chose from array.
// 4. Print all unique nCr combinations.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void combinations(vector <int> a, int n, int r, int size, vector <int> data, int current){
    
    if(size == r){
        for(int i = 0; i < r; i++){
            cout << data[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    if(current >= n){
        return;
    }
    
    // Combinations : Including current element
    data[size] = a[current];
    combinations(a, n, r, size+1, data, current+1);
    
    // Combinations : Including current element
    while(a[current] == a[current + 1])
        current++;

    combinations(a, n, r, size, data, current+1);    
}

void printCombinations(vector <int> a, int n, int r){
    
    vector <int> data(r);
    
    combinations(a, n, r, 0, data, 0);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, r, i;
    
    cin >> n;
    vector <int> a(n);
    
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cin >> r;
    
    sort(a.begin(), a.end());
    
    printCombinations(a, n, r);
    
    return 0;
}
