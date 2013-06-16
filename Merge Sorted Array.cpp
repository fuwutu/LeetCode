class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int i = m + n - 1;
        int ai = m - 1;
        int bi = n - 1;
        while (ai >= 0 && bi >= 0)
        {
            if (A[ai] > B[bi])
            {
                A[i--] = A[ai--];
            }
            else
            {
                A[i--] = B[bi--];
            }
        }
        if (bi >= 0)
        {
            copy(B, B + bi + 1, A);
        }
    }
};
