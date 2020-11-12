#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k, i;
    vector<int> v;
    
    cin >> n;
    
    for(i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        v.push_back(r);
    }
    
    cin >> k;
    
    int maxSum[n];
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(i = 0; i < n; i++)
    {
        max_ending_here += v[i];

        max_so_far = max(max_ending_here, max_so_far);
        maxSum[i]  = max_so_far;

        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    
    if(k == 1)
    {
        cout << maxSum[n-1];
        return 0;
    }
    
    int sum = 0;
    for(i = 0; i < k; i++)
        sum += v[i];
    
    int result = sum;
    
    for(i = k; i < n; i++)
    {
        sum = sum - v[i - k] + v[i];
        
        result = max(result, sum);
        result = max(result, result + maxSum[i - k]);
    }
    
    
    cout << result;   
    
    
    return 0;
}
