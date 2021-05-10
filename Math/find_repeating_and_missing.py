# 1. You are given an arrya of integers whose size is n.
# 2. The array contains elements from 1 to n. It is given that one of the numbers
# is missing and one of the numbers is repeated.
# 3. You have to print repeating and missing element respectively.

from operator import mul
from math import factorial

n = int(input())
arr = [int(i) for i in input().split(" ")]
s = sum(arr)
m = 1
for i in range(n):
    m *= arr[i]
sn = n*(n+1)//2
f = factorial(n)

x = int(((s-sn)*f)/(m-f))
y = int((m*x)/f)

print(y)
print(x)