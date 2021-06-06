// 1. You are given 2 numbers. You have to print minimum number of bits to be flipped
// so that both numbers become equal.

#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unsigned int m , n;
    cin >> m >> n;
    
    unsigned int i = m ^ n;
    i = (i & 0x55555555) + ((i>>1) & 0x55555555);
    i = (i & 0x33333333) + ((i>>2) & 0x33333333);
    i = (i & 0x0F0F0F0F) + ((i>>4) & 0x0F0F0F0F);
    i = (i * 0x01010101) >> 24;
    
    cout << i;
    
    return 0;
}
