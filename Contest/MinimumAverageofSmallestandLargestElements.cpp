#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        double finalAns = INT_MAX;
        vector<double> tempList;
        int low = 0, high = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            tempList.push_back((nums[i] + nums[nums.size() - i - 1]) / 2.0);

        for (double item : tempList)
            finalAns = min(finalAns, item);

        cout << typeid(finalAns).name() << endl;
        return finalAns;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 7, 8, 9};

    cout << s.minimumAverage(v) << endl;
    return 0;
}