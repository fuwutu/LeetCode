class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n <= 2)
        {
            return n;
        }
        
        int length = 2;
        for (int i = 2; i < n; ++i)
        {
            if (A[i] != A[length - 1] || A[i] != A[length - 2])
            {
                A[length++] = A[i];
            }
        }
        return length;
    }
};
