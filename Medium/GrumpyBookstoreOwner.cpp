#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int satisfiedCustomer = 0, additionalCustomer = 0, temp;

        for (int i = 0; i < grumpy.size(); i++)
        {
            satisfiedCustomer += (1 - grumpy[i]) * customers[i];
        }
        for (int i = 0; i < grumpy.size(); i++)
        {
            if (grumpy[i])
            {
                temp = 0;
                for (int j = i; j < (i + minutes) && j < grumpy.size(); j++)
                    temp = grumpy[j] ? temp + customers[j] : temp;
                additionalCustomer = max(temp, additionalCustomer);
            }
        }

        return satisfiedCustomer + additionalCustomer;
    }
};

int main()
{
    Solution s;
    vector<int> customers = {10, 5};
    vector<int> grumpy = {0, 1};
    cout << s.maxSatisfied(customers, grumpy, 2);
    return 0;
}