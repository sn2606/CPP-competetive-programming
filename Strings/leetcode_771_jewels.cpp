// You're given strings jewels representing the types of stones that are jewels, 
// and stones representing the stones you have. Each character in stones is a type of stone you have. 
// You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int hashTableLower[26] = {0};
        int hashTableUpper[26] = {0};
        int jewelCount = 0;
        
        for(int i = 0; i < jewels.size(); i++){
            if(jewels[i] < 97)
                hashTableUpper[jewels[i]%26]++;
            else
                hashTableLower[jewels[i]%26]++;            
        }
        
        for(int i = 0; i < stones.size(); i++){
            if((stones[i] < 97 && hashTableUpper[stones[i]%26]) || (stones[i] >= 97 && hashTableLower[stones[i]%26])){
                jewelCount++;
            }
        }
        
        return jewelCount;
    }
};