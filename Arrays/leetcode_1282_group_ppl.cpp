// There are n people that are split into some unknown number of groups. 
// Each person is labeled with a unique ID from 0 to n - 1.
// You are given an integer array groupSizes, where groupSizes[i] is the 
// size of the group that person i is in. For example, if groupSizes[1] = 3, 
// then person 1 must be in a group of size 3.
// Return a list of groups such that each person i is in a group of size groupSizes[i].
// Each person should appear in exactly one group, and every person must be in a group. 
// If there are multiple answers, return any of them. 
// It is guaranteed that there will be at least one valid solution for the given input. 

# include <iostream>
# include <algorithm>
# include <vector>
# include <unordered_map>
using namespace std;

// O(nlogn solution with sorting)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>> res;
        vector<pair<int, int>> groupInfo;
        int n = groupSizes.size();
        
        for(int i = 0; i < n; i++){
            groupInfo.push_back(make_pair(groupSizes[i], i));
        }
        
        // for(int i = 0; i < n; i++){
        //     cout << groupInfo[i].second << "\n";
        // }
        
        sort(groupInfo.begin(), groupInfo.end());
        
        for(int i = 0; i < n;){
            vector <int> b;
            int j = i;
            while(j < i+groupInfo[i].first){
                b.push_back(groupInfo[j].second);
                j++;
            }
            res.push_back(b);
            i += groupInfo[i].first;
            
        }
        
        return res;
        
    }
};


// O(n) solution with hashmap
class Solution2 {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>> res;
        unordered_map<int, vector<int>> groupInfo;
        
        for(int i = 0; i < groupSizes.size(); i++){
            
            if(groupInfo.count(groupSizes[i]) > 0){
                groupInfo[groupSizes[i]].push_back(i);
            }else{
                groupInfo[groupSizes[i]] = vector<int>{i};
            }
            
            if(groupInfo[groupSizes[i]].size() == groupSizes[i]){
                res.push_back(groupInfo[groupSizes[i]]);
                groupInfo.erase(groupSizes[i]);
            }
            
        }
        
        return res;
        
    }
};