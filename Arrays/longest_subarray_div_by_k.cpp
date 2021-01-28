// Find the longest subarray sum divisible by k

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, i; // j;
    
    cin >> n;
    
    int arr[n];
    
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> k;
    
    int prefixSumMod[n] = {0};
    
    prefixSumMod[0] = (arr[0] + k) % k;
    for(i = 1; i < n; i++){
        prefixSumMod[i] = ((prefixSumMod[i-1] + (arr[i] % k)) + k) % k;
    }
    
//     for(int l : prefixSumMod)
//         cout << l << " ";
    
//     cout << "\n";
    
    int modInd[k];
    
    for(i = 0; i < k; i++)
        modInd[i] = -1;
    
    int ans = 0, ind1 = -1, ind2 = -1;
    
    for(i = 0; i < n; i++){
        if(modInd[prefixSumMod[i]] == -1){
            modInd[prefixSumMod[i]] = i;
        }
        if(prefixSumMod[i] == 0){
            ans = i+1;
            ind1 = 0;
            ind2 = i+1;
        }else{
            if(ans < (i - modInd[prefixSumMod[i]])){
                ans = (i - modInd[prefixSumMod[i]]);
                ind1 = modInd[prefixSumMod[i]]+1;
                ind2 = i+1;
            }             
        }
    }
    
//     for(int l : modInd)
//         cout << l << " ";
    
//     cout << "\n";
    
    for(i = ind1; i < ind2; i++)
        cout << arr[i] << " ";
    
    
    return 0;
}
