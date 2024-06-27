#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        if (edges.size() < 3)
            return -1;
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 2}, {2, 3}, {4, 2}}; // 1, 2 ], [ 2, 3 ], [ 4, 2 ] ];
    cout << s.findCenter(v);
}