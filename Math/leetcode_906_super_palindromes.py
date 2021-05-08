# Let's say a positive integer is a super-palindrome if it is a palindrome, 
# and it is also the square of a palindrome.
# Given two positive integers left and right represented as strings, 
# return the number of super-palindromes integers in the inclusive range [left, right].

class Solution:
    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]
    
    def superpalindromesInRange(self, left: str, right: str) -> int:
        palindromes = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        for i in range(1, 10000):
            p1 = str(i) + str(i)[::-1]
            palindromes.append(p1)
            for j in range(10):
                p2 = str(i) + str(j) + str(i)[::-1]
                palindromes.append(p2)
                
        count = 0
        palindromes = list(map(int, palindromes))
        palindromes.sort()
        for i in palindromes:
            if i*i >= int(left) and i*i <= int(right) and self.isPalindrome(str(i*i)):
                count += 1
                
        return count        