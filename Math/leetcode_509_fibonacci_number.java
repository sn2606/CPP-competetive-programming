// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
// such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

class Solution509 {
    public int fib(int n) {
        double sf = Math.sqrt(5);
        double Phi = (sf + 1)/2;
        double ans = (Math.pow(Phi, n) - Math.pow(-Phi, -n))/sf;
    
        return (int)ans;        
    }
}