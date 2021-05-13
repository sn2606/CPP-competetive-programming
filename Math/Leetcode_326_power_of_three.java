// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

class Solution326 {
    public boolean isPowerOfThree(int n) {
        return (n <= 0) ? false : (1162261467 % n == 0);
    }
}