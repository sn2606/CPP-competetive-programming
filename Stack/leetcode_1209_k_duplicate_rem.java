// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent 
// and equal letters from s and removing them, causing the left and the right side of the deleted 
// substring to concatenate together.
// We repeatedly make k duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. 
// It is guaranteed that the answer is unique.

class Solution {
    public String removeDuplicates(String s, int k) {
        int n = s.length();
        int[] count = new int[n];
        StringBuilder sb = new StringBuilder();
        char[] schar = s.toCharArray();
        
        for(char c : schar) {
            sb.append(c);
            int l = sb.length() - 1;
            count[l] = ((l > 0 && sb.charAt(l) == sb.charAt(l-1)) ? count[l-1] : 0) + 1;
            if(count[l] >= k){
                sb.delete(l-k+1, l+1);
            }
        }
        
        return sb.toString();
    }
}