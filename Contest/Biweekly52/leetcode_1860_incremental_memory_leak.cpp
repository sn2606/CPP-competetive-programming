// 1860. Incremental Memory Leak
// User Accepted:4146
// User Tried:4298
// Total Accepted:4225
// Total Submissions:6424
// Difficulty:Medium
// You are given two integers memory1 and memory2 representing the available memory in bits on two memory sticks. There is currently a faulty program running that consumes an increasing amount of memory every second.

// At the ith second (starting from 1), i bits of memory are allocated to the stick with more available memory (or from the first memory stick if both have the same available memory). If neither stick has at least i bits of available memory, the program crashes.

// Return an array containing [crashTime, memory1crash, memory2crash], where crashTime is the time (in seconds) when the program crashed and memory1crash and memory2crash are the available bits of memory in the first and second sticks respectively.

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        vector<int> res(3);
        res[0] = 1;
        res[1] = m1;
        res[2] = m2;
        
        int i;
        
        for(i = 1; ; i++){
            if(m1 > m2 && i <= m1){
                m1 -= i;
            }else if(m1 == m2 && i <= m1){
                m1 -= i;
            }else if(m1 < m2 && i <= m2){
                m2 -= i;
            }else{
                break;
            }
            
            // cout << m1 << " " << m2 << "\n";
        }
        
        res[0] = i;
        res[1] = m1;
        res[2] = m2;
        
        return res;
    }
};