// A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. 
// Given a byte, swap the two nibbles in it. For example 100 is be represented as 01100100 
// in a byte (or 8 bits). The two nibbles are (0110) and (0100). If we swap the two nibbles, 
// we get 01000110 which is 70 in decimal.


#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unsigned int n1 = 15, n2 = n1 << 4, n;
    cin >> n;
    n1 = ((n1 & n) << 4);
    n2 = ((n2 & n) >> 4);
    
    cout << (n1 | n2);   
    
    
    return 0;
}