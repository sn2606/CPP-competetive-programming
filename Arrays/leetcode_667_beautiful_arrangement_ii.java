// Given two integers n and k, you need to construct a list which contains n different positive 
// integers ranging from 1 to n and obeys the following requirement:
// Suppose this list is [a1, a2, a3, ... , an], then the list 
// [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
// If there are multiple answers, print any of them.

class Solution {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int m1 = 1;
        int m2 = k+1;
        
        for(int i = 0; i <= k; i++){
            if(i%2 == 0){
                ans[i] = m1;
                m1++;
            }else{
                ans[i] = m2;
                m2--;
            }
        }
        
        for(int i = k+1; i < n; i++){
            ans[i] = i+1;
        }
        
        return ans;
        
    }
}