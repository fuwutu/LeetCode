class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int count[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i)
        {
            count[A[i]] += 1;
        }
        int k = 0;
        for (int color = 0; color <= 2; ++color)
        {
            for (int j = 0; j < count[color]; ++j)
            {
                A[k++] = color;
            }
        }
    }
};
