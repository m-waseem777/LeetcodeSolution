#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low, high, mid, finalAns;
        low = 0;
        high = 0;
        finalAns = -1;

        for (int item : bloomDay)
            high = max(item, high);

        while (low <= high)
        {
            mid = (high + low) / 2;

            if (MakeDiffPair(bloomDay, mid, k) >= m)
            {
                finalAns = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return finalAns;
    }

    int MakeDiffPair(vector<int> &bloomDay, int mid, int k)
    {
        int diffPairCount = 0, kCount = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
                kCount++;
            else
                kCount = 0;

            if (kCount == k)
            {
                diffPairCount++;
                kCount = 0;
            }
        }

        return diffPairCount;
    }
};

int main()
{
    Solution s;
    int m, k;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    m = 3;
    k = 1;
    cout << s.minDays(bloomDay, m, k) << endl; // 3

    bloomDay = {7, 7, 7, 7, 12, 7, 7};
    m = 2;
    k = 3;
    cout << s.minDays(bloomDay, m, k) << endl; // 12

    bloomDay = {1, 10, 3, 10, 2, 10};
    m = 3;
    k = 2;
    cout << s.minDays(bloomDay, m, k) << endl; // 10

    bloomDay = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    m = 4;
    k = 2;
    cout << s.minDays(bloomDay, m, k) << endl; // 9
    return 0;
}