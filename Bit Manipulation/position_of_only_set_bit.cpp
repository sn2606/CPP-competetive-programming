// 1. You are given number. You have to print position of only set bit such that 
// position of LSB is marked as 1.
// 2. If there are more than 1 set bits in a number, then print 'Invalid'.

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
    
    int i = 1;
    while(n){
        if(n & 1){
            if(n >> 1){
                cout << "Invalid";
            }else{
                cout << i;
            }
            
            break;
        }else{
            n >>= 1;
        }
        i++;
    }
    
    return 0;
}
