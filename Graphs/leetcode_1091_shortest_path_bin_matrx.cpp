// In an N by N square grid, each cell is either empty (0) or blocked (1).
// A clear path from top-left to bottom-right has length k if and only if
// it is composed of cells C_1, C_2, ..., C_k such that:
// Adjacent cells C_i and C_{i+1} are connected 8-directionally
// (ie., they are different and share an edge or corner)
// C_1 is at location (0, 0) (ie. has value grid[0][0])
// C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
// If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
// Return the length of the shortest such clear path from top-left to bottom-right.
// If such a path does not exist, return -1.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int res = 0;
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        grid[0][0] = 1;
        res++;

        int moves[8][2] = {{1, 1}, {1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

        while (!q.empty())
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1)
                return grid[x][y];
                // return res;

            // int flag = 0;

            for (auto m : moves)
            {

                int i = x + m[0];
                int j = y + m[1];

                if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                    grid[i][j] = grid[x][y] + 1;

                    // if (!flag)
                    // {
                    //     flag = 1;
                    //     res++;
                    // }
                }
            }
        }

        return -1;
    }
};