class Solution
{
public:
    int trap(int A[], int n)
    {
        int water = 0;
        
        if (n > 0)
        {
            int* left = new int[n];
            int* right = new int[n];
            
            left[0] = A[0];
            int top = A[0];
            for (int i = 1; i < n; ++i)
            {
                top = max(top, A[i]);
                left[i] = top;
            }
            
            right[n-1] = A[n-1];
            top = A[n-1];
            for (int i = n - 2; i >= 0; --i)
            {
                top = max(top, A[i]);
                right[i] = top;
            }
            
            for (int i = 0; i < n; ++i)
            {
                water += (min(left[i], right[i]) - A[i]);
            }
            
            delete[] left;
            delete[] right;
        }
        
        return water;
    }
};
