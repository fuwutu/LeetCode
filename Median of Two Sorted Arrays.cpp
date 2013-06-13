class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if (m == 0)
        {
            return (B[(n - 1) /2] + B[n / 2]) / 2.0;
        }
         
        if (n == 0)
        {
            return (A[(m - 1) / 2] + A[m / 2]) / 2.0;
        }
         
        int total = m + n;
        int half = total / 2 + 1;
        int left = max(0, half - n);
        int right = min(m, half - 0);
        while (left < right)
        {
            int a = (left + right) / 2;
            int b = half - a;
 
            if (a == 0)
            {
                if (m == 0 || B[b-1] <= A[0])
                {
                    break;
                }
                else
                {
                    left = a + 1;
                }
                continue;
            }
 
            if (b == 0)
            {
                if (n == 0 || A[a-1] <= B[0])
                {
                    break;
                }
                else
                {
                    right = a - 1;
                }
                continue;
            }
 
            if (A[a - 1] >= B[b - 1])
            {
                if (b == n || A[a - 1] <= B[b])
                {
                    break;
                }
                else
                {
                    right = a - 1;
                }
            }
            else
            {
                if (a == m || B[b - 1] <= A[a])
                {
                    break;
                }
                else
                {
                    left = a + 1;
                }
            }
        }
         
        int a = (left + right) / 2;
        int b = half - a;
 
        if (a == 0)
        {
            if (total % 2 == 1)
            {
                return B[b - 1];
            }
            else
            {
                return (B[b - 2] + B[b - 1]) / 2.0;
            }
        }
 
        if (b == 0)
        {
            if (total % 2 == 1)
            {
                return A[a - 1];
            }
            else
            {
                return (A[a - 2] + A[a - 1]) / 2.0;
            }
        }
         
        if (A[a - 1] >= B[b - 1])
        {
            if (total % 2 == 1)
            {
                return A[a - 1];
            }
            else
            {
                if (a == 1)
                {
                    return (B[b - 1] + A[a - 1]) / 2.0;
                }
                else
                {
                    return (max(B[b - 1], A[a - 2]) + A[a - 1]) / 2.0;
                }
            }
        }
        else
        {
            if (total % 2 == 1)
            {
                return B[b - 1];
            }
            else
            {
                if (b == 1)
                {
                    return (A[a - 1] + B[b - 1]) / 2.0;
                }
                else
                {
                    return (max(A[a - 1], B[b - 2]) + B[b - 1]) / 2.0;
                }
            }
        }
    }
};
