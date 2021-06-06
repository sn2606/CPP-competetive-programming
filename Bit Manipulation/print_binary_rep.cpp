// Print binary represention of a number

#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin >> n;
    vector<int>digs;
    while(n){
        digs.insert(digs.begin(), (n & 1));
        n >>= 1;
    }
    
    for(auto i : digs){
        cout << i;
    }
    
    return 0;
}