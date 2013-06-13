class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 0;
        int b = 0;
        int c = 1;
        for (int i = 0; i < n; ++i)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
