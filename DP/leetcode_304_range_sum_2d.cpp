// Given a 2D matrix matrix, handle multiple queries of the following type:
// Calculate the sum of the elements of matrix inside the rectangle defined by its 
// upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the 
// elements of matrix inside the rectangle defined by 
// its upper left corner (row1, col1) and lower right corner (row2, col2).

# include <iostream>
# include <vector>
using namespace std;

// prefix sum -> O(mn) space, O(n) time
class NumMatrix1 {
private:
    vector<vector<int>>prefixSum;
    int r, c;
public:
    NumMatrix1(vector<vector<int>>& matrix) {
        
        r = matrix.size();
        c = matrix[0].size();
        prefixSum.resize(r+1, vector<int>(c+1, 0));
        
        for(int i = 0; i < r; i++){
            int sum = 0;
            for(int j = 0; j < c; j++){
                sum += matrix[i][j];
                prefixSum[i+1][j+1] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        for(int i = row1+1; i <= row2+1; i++){
            res += (prefixSum[i][col2+1] - prefixSum[i][col1]);
        }
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// O(mn) space, O(1) time, inclusion exclusion principle
class NumMatrix {
private:
    vector<vector<int>>prefixSum;
    int r, c;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        r = matrix.size();
        c = matrix[0].size();
        prefixSum.resize(r+1, vector<int>(c+1, 0));
        
        for(int i = 0; i < r; i++){
            int sum = 0;
            for(int j = 0; j < c; j++){
                sum += matrix[i][j];
                prefixSum[i+1][j+1] = prefixSum[i][j+1] + sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        res += (prefixSum[row2+1][col2+1] + prefixSum[row1][col1]);
        res -= (prefixSum[row1][col2+1] + prefixSum[row2+1][col1]);
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */