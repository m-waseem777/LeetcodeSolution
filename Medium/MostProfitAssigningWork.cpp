#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int finalAns = 0, currProfit, idx, tempIdx = 0;
        vector<pair<int, int>> dpPair = GetDPPairs(difficulty, profit);

        sort(worker.begin(), worker.end());

        for (int item : worker)
        {
            currProfit = 0;
            idx = tempIdx;
            while (idx < dpPair.size())
            {
                if (dpPair[idx].first <= item && dpPair[idx].second > currProfit)
                {
                    currProfit = dpPair[idx].second;
                    tempIdx = idx;
                }
                else
                    break;
                idx++;
            }

            finalAns += currProfit;
        }

        return finalAns;
    }

    vector<pair<int, int>> GetDPPairs(vector<int> &difficulty, vector<int> &profit)
    {
        vector<pair<int, int>> dpPair;
        for (int i = 0; i < difficulty.size(); i++)
        {
            dpPair.push_back(make_pair(difficulty[i], profit[i]));
        }

        sort(dpPair.begin(), dpPair.end());
        return dpPair;
    }
};

int main()
{
    vector<int> d = {68, 35, 52, 47, 86};
    vector<int> p = {67, 17, 1, 81, 3};
    vector<int> w = {92, 10, 85, 84, 82};

    Solution s;
    cout << s.maxProfitAssignment(d, p, w) << endl;
    return 0;
}