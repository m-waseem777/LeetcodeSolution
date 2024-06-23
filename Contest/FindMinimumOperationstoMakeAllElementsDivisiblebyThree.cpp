#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int finalAns = 0;

        for (int item : nums)
        {
            if (item % 3 != 0)
            {
                finalAns++;
            }
        }

        return finalAns;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    cout << s.minimumOperations(v) << endl;
}