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

class Solution2 {
public:
    int xorOperation2(int n, int start) {
        int first = start & 1;
        start = start >> 1;
        if(start % 2 == 0){
            switch(n % 4){
                case 0: return 0;
                case 1: return ((start + n - 1) << 1) + first;
                case 2: return 2;
                case 3: return ((1 ^ (start + n - 1)) << 1) + first;
            } 
        } else {
            switch(n % 4){
                case 0: return (start ^ 1 ^ (start + n - 1)) << 1;
                case 1: return (start << 1) + first;
                case 2: return (start ^ (start + n - 1)) << 1;
                case 3: return ((start ^ 1) << 1) + first;
            } 
        }
        return 0; //unreachable
    }
};