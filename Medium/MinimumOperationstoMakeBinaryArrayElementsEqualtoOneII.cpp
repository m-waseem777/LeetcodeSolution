#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int finalAns = 0;
        int flag = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == flag)
            {
                flag = (1 - flag);
                finalAns++;
            }
        }

        return finalAns;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 0, 0, 0};

    cout << s.minOperations(v) << endl;
}