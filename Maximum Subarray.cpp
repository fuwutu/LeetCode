class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        int min = 0, max = A[0], sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += A[i];
            if (sum - min > max)
            {
                max = sum - min;
            }
            if (sum < min)
            {
                min = sum;
            }
        }
        return max;
    }
};
