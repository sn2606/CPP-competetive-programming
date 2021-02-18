// In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there.
// We are allowed to increase the height of any number of buildings, by any amount
// (the amounts can be different for different buildings). Height 0 is considered to be a building as well.
// At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right,
// must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles
// formed by all the buildings when viewed from a distance. See the following example.
// What is the maximum total sum that the height of the buildings can be increased?

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {

        int n = grid.size();

        vector<int> xsky(n);
        vector<int> ysky(n);

        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            x = 0;
            y = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > y)
                {
                    y = grid[i][j];
                }

                if (grid[j][i] > x)
                {
                    x = grid[j][i];
                }
            }

            xsky[i] = x;
            ysky[i] = y;
        }

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int m = ysky[i] > xsky[j] ? xsky[j] : ysky[i];
                res += (grid[i][j] < m) ? (m - grid[i][j]) : 0;
            }
        }

        return res;
    }
};