// Given an array of n positive integers and a number k. 
// Find the minimum number of swaps required to bring all 
// the numbers less than or equal to k together.
// A simple approach is to use two pointer technique and sliding window.
// Find count of all elements which are less than or equals to ‘k’. 
// Let’s say the count is ‘cnt’
// Using two pointer technique for window of length ‘cnt’, 
// each time keep track of how many elements in this range are greater than ‘k’. 
// Let’s say the total count is ‘bad’.
// Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. 
// This will be the final answer.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n, k, i, j;
    vector <int> v;
    
    cin >> n;
    
    for(i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        v.push_back(r);
    }
    
    cin >> k;
    
    // Counting the numbers less than k in the array
    int count = 0;
    for(i = 0; i < n; i++)
    {
        if(v[i] <= k)
            count++;
    }
    
    
    // Current "window" from 0 to count
    // unwanted elements (greater than k) in that will need to be swapped
    int u = 0;
    for(i = 0; i < count; i++)
    {
        if(v[i] > k)
            u++;
    }
    
    int result = u;
    
    // Between i+1 and j is the current window. 
    // We are sliding the window till last element
    for(i = 0, j = count; j < count; i++, j++)
    {
        if(v[i] > k)
        {
            u--; // because the window starts from next index
        }
        
        if(v[j] > k)
        {
            u++; // because this index is included in the window
        }
        
        // Update the minimum number of swaps required
        result = min(result, u);        
    }
    
     
    cout << result;    
    
    return 0;
}
