class Solution
{
public:
    int numTrees(int n)
    {
        int total[100] = {1};
        for (int i = 1; i <= n; ++i)
        {
            total[i] = (total[(i - 1) / 2] * total[i / 2] * (2 - i % 2));
            for (int j = 0; j < (i - 1) / 2; ++j)
            {
                total[i] += (total[j] * total[i - 1 - j] * 2);
            }
        }
        return total[n];
    }
};
