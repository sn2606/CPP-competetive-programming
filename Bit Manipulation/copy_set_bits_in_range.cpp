// 1. You are given 2 integers, namely x and y. You are also given range with the help
// of 2 integers : r and l.
// 2. Given that if number of bits is n, least significant bit is marked as 1 and
// most significant bits is n.
// 3. Now, you have to copy set bits between r and l in y to x.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x, y, l, r;
    
    cin >> x >> y >> l >> r;
    int mask = (1 << (r-l+1)) - 1;
    mask = (((mask) << (l-1)) & y);
    x |= mask;
    
    cout << x;
    
    return 0;
}