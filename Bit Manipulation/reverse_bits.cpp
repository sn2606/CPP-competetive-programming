// Reverse bits in a number efficiently
// O(log2(n)) time, O(1) space

#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unsigned int n, ans = 0;
    cin >> n;
    
    while(n){
        ans <<= 1;
        ans |= (n & 1);
        n >>= 1;
    }
    
    cout << ans;
    
    return 0;
}
