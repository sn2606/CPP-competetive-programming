// Given an integer n and an integer start.
// Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.
// Return the bitwise XOR of all elements of nums.

# include <iostream>
using namespace std;

class Solution
{
    int xorOperationB(int n, int start)
    {
        if (n % 2 == 0)
            return (n / 2) & 1;
        else
            return ((n / 2) & 1) ^ (start + n - 1);
    }
    int xorOperationA(int n, int start)
    {
        if (start & 1)
            return (start - 1) ^ xorOperationB(n + 1, start - 1);
        else
            return xorOperationB(n, start);
    }
public:
    int xorOperation(int n, int start)
    {
        int ret = 2 * xorOperationA(n, start / 2);
        if (n & start & 1) ret++;
        return ret;
    }
};