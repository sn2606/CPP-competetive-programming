// LeetCode 191
// Write a function that takes an unsigned integer 
// and returns the number of '1' bits it has 
// (also known as the Hamming weight, popcount, sideways sum).
// Bitmasking
// 0x55555555 = 01010101010101010101010101010101
// 0x33333333 = 00110011001100110011001100110011
// 0x0F0F0F0F = 00001111000011110000111100001111
// 0x01010101 = 00000001000000010000000100000001

# include <iostream>
using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t i) {
        // // int i;
        //  n = n - ((n >> 1) & 0x55555555);
        //  n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        //  return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        
        // Variable Precision Swar algorithm
        i = (i & 0x55555555) + ((i>>1) & 0x55555555);
        i = (i & 0x33333333) + ((i>>2) & 0x33333333);
        i = (i & 0x0F0F0F0F) + ((i>>4) & 0x0F0F0F0F);
        i = (i * 0x01010101) >> 24;
        return i;
    }
};