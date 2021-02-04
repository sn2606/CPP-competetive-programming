// Given an array of numbers, arrange them in a way that yields the largest value. 
// For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 
// gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, 
// then the arrangement 998764543431 gives the largest value.

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compareString(string a, string b){
    string s1;
    string s2;
    if(a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0){
        s1 = a+b;
        s2 = b+a;        
        return s1 > s2;
    }else{
        return a > b;
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector <string> ss(n);
    // int m = n;
    
    for(int i = 0; i < n; i++){
        cin >> ss[i];
    }
    
    sort(ss.begin(), ss.end(), compareString);
    
    for(string s: ss)
        cout << s;
    
    
    return 0;
}