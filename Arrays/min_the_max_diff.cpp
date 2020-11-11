#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, k, i;
    vector <int> v;
    
    cin >> n;
    
    for(i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        v.push_back(r);
    }
    
    cin >> k;
    
    sort(v.begin(), v.end());
    
    int diff = v[n-1] - v[0];
    
    int small = v[0] + k;
    int large = v[n-1] - k;
    
    if(small > large)
    {
        swap(small, large);
    }
    
    for(i = 1; i < n; i++)
    {
        int s = v[i] - k;
        int a = v[i] + k;
        
        // If the following condition is true, it won't change the max difference        
        if(s >= small || a <= large)
            continue;
        
        if(large - s <= a - small)
        {
            small = s;
        }
        else if(a - small <= large - s)
        {
            large = a;
        }
    }
    
    cout << min(diff, large - small);
    
    
    return 0;
}
