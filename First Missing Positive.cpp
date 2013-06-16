class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        if (n == 0)
        {
            return 1;
        }
        
        for (int i = 0; i < n; ++i)
        {
            while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            {
                int x = A[i];
                A[i] = A[x - 1];
                A[x - 1] = x;
            }
        }
        
        int m = 1;
        while (m <= n && A[m-1] == m)
        {
            ++m;
        }
        return m;
    }
};
