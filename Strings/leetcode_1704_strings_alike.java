// You are given a string s of even length. Split this string into two halves of equal lengths, 
// and let a be the first half and b be the second half.
// Two strings are alike if they have the same number of vowels 
// ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
// Notice that s contains uppercase and lowercase letters.
// Return true if a and b are alike. Otherwise, return false.

import java.util.*;

class Solution {
    public boolean halvesAreAlike(String s) {
        var vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        int a = 0, b = 0;
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            a += vowels.contains(s.charAt(i)) ? 1 : 0;
            b += vowels.contains(s.charAt(j)) ? 1 : 0;
        }
        return a == b;
    }
    
    public boolean halvesAreAlike2(String s) {
        int n = s.length();
        int v1 = 0;
        int v2 = 0;
        
        for(int i = 0; i < n/2; i++){
            if(s.charAt(i) == 'a'|| s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || 
               s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || 
               s.charAt(i) == 'O' || s.charAt(i) == 'U'){
                v1++;
            }
        }
        
        for(int i = n/2; i < n; i++){
            if(s.charAt(i) == 'a'|| s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || 
               s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || 
               s.charAt(i) == 'O' || s.charAt(i) == 'U'){
                v2++;
            }
        }
        
        return v1==v2;
    }
}