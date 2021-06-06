// Write an Efficient Method to Check if a Number is Multiple of 3
// Yes, everyone and their god uses modulo, but this is DSA bitch. Buckle up for the ride of insanity.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hammingWeight(unsigned int i) {
        
    // Variable Precision Swar algorithm
    i = (i & 0x55555555) + ((i>>1) & 0x55555555);
    i = (i & 0x33333333) + ((i>>2) & 0x33333333);
    i = (i & 0x0F0F0F0F) + ((i>>4) & 0x0F0F0F0F);
    i = (i * 0x01010101) >> 24;
    return i;
}

bool isMultipleOfThree(unsigned int n){
    
    if(n == 0)
        return 1;
    
    if(n == 1)
        return 0;
    
    unsigned int even_set, odd_set;
    
    even_set = n & 0x55555555; // set bits at even places
    odd_set = n & 0xAAAAAAAA; // set bits at odd places
    
    int even_count = hammingWeight(even_set); // count number of set bits at even places   
    int odd_count = hammingWeight(odd_set); // count number of set bits at odd places
    
    return isMultipleOfThree((unsigned int)abs(even_count - odd_count));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    unsigned int n;
    cin >> n;

    cout << (isMultipleOfThree(n) ? "true" : "false");
    
    return 0;
}
