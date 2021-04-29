// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach 
// the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid

class Solution63 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        if (m == 1 || n == 1) {
            return 1;
        }

        int[][] pathCount = new int[m][n];

        pathCount[m - 1][n - 1] = 0;
        pathCount[m - 1][n - 2] = (obstacleGrid[m - 1][n - 2] == 1) ? 0 : 1;
        pathCount[m - 2][n - 1] = (obstacleGrid[m - 2][n - 1] == 1) ? 0 : 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                pathCount[i][j] += (i + 1 >= m || obstacleGrid[i][j] == 1) ? 0 : (pathCount[i + 1][j]);
                pathCount[i][j] += (j + 1 >= n || obstacleGrid[i][j] == 1) ? 0 : (pathCount[i][j + 1]);
            }
        }

        // for(int i = 0; i < m; i++){
        // for(int j = 0; j < n; j++){
        // System.out.print(pathCount[i][j] + " ");
        // }
        // System.out.println();
        // }

        return pathCount[0][0];
    }
}