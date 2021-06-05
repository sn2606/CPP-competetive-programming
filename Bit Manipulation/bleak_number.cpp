// A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and 
// set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int countSetBits(int n){
    // VPSWAR
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = n * 0x01010101;
    n = n >> 24;
    
    return n;
}

bool isBleak(int n){
    for(int x = n-ceil(log2(n)); x < n; x++){
        if(x + countSetBits(x) == n){
            return false;
        }
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin >> n;
    
    cout << (isBleak(n) ? "Yes" : "No");
    
    return 0;
}
