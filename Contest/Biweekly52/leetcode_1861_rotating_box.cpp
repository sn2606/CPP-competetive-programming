// 1861. Rotating the Box
// User Accepted:2847
// User Tried:3283
// Total Accepted:2941
// Total Submissions:5133
// Difficulty:Medium
// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r = box.size(), c = box[0].size();
        vector<vector<char>>res(c, vector<char>(r));
        
        for(int i = 0; i < r; i++){
            int k = 0;
            for(int j = 0; j < c; j++){
                if(box[i][j] == '*'){
                    sort(box[i].begin() + k, box[i].begin() + j, greater<char>());
                    k = j+1;
                }                
            }
            
            sort(box[i].begin() + k, box[i].end(), greater<char>());
            
            for(int j = 0; j < c; j++){
                res[j][r-1-i] = box[i][j];
            }
        }
        
        return res;
    }
};