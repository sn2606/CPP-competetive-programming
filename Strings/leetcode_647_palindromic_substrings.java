// Given a string, your task is to count how many palindromic substrings in this string.
// The substrings with different start indexes or end indexes are counted as different 
// substrings even they consist of same characters.

// O(n^2) solution
class Solution647 {
    public int countSubstrings(String s) {
        int count = 1;
        if (s.length() == 0) {
            return 0;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            count = check(s, i, i, count);
            count = check(s, i, i + 1, count);
        }

        return count;
    }

    int check(String s, int i, int j, int count) {
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            count++;
            i--;
            j++;
        }

        return count;
    }
}