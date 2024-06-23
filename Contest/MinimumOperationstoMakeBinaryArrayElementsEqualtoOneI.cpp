#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int finalAns = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] == 0)
            {
                finalAns++;
                nums[i] = 1;
                nums[i + 1] = nums[i + 1] == 1 ? 0 : 1;
                nums[i + 2] = nums[i + 2] == 1 ? 0 : 1;
            }
        }

        for (int item : nums)
        {
            if (item == 0)
                return -1;
        }

        return finalAns;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 1, 1};

    cout << s.minOperations(v) << endl;
}