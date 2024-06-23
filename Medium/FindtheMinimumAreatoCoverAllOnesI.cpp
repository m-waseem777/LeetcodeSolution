#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int minIdxInRow = grid[0].size(), maxIdxInRow = -1, minIdxInCol = grid.size(), maxIdxInCol = -1;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    minIdxInRow = min(minIdxInRow, j);
                    maxIdxInRow = max(maxIdxInRow, j);
                    minIdxInCol = min(minIdxInCol, i);
                    maxIdxInCol = max(maxIdxInCol, i);
                }
            }
        }

        return (maxIdxInRow - minIdxInRow + 1) * (maxIdxInCol - minIdxInCol + 1);
    }
};

int main()
{
    Solution s;

    vector<vector<int>> vect = {{0, 1, 0}, {1, 0, 1}};
    cout << s.minimumArea(vect) << endl;
    vect = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    cout << s.minimumArea(vect) << endl;
    vect = {{0, 0},
            {1, 0}};
    cout << s.minimumArea(vect) << endl;

    return 0;
}