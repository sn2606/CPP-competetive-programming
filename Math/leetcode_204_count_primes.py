# Count the number of prime numbers less than a non-negative number, n.

from math import sqrt

class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        
        sieve = [1]*n
        sieve[0] = 0
        sieve[1] = 0
        
        for i in range(2, int(sqrt(n))+1):
            if(sieve[i] != 0):
                sieve[i*i:n:i] = [0]*(((n-1) - (i*i))//i  + 1)
                
        return sum(sieve)