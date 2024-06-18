#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int high, low, num1, num2;

        low = 0;
        high = sqrt(c) + 1;

        while (low <= high)
        {
            num1 = low * low;
            num2 = high * high;

            if (num1 + num2 == c)
                return true;

            if (num1 + num2 > c)
                high--;
            else
                low++;
        }

        return false;
    }
};

int main()
{
    Solution s;

    cout << s.judgeSquareSum(5) << endl;
    cout << s.judgeSquareSum(3) << endl;
    cout << s.judgeSquareSum(7) << endl;
    cout << s.judgeSquareSum(10) << endl;
    cout << s.judgeSquareSum(8) << endl;
    return 0;
}