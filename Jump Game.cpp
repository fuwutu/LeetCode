class Solution
{
public:
    bool canJump(int A[], int n)
    {
        if (n == 1)
        {
            return true;
        }
         
        for (int i = n - 2; i >= 0; --i)
        {
            if (A[i] == 0)
            {
                int p = i;
                for (--i; i >= 0; --i)
                {
                    if (A[i] + i > p)
                    {
                        break;
                    }
                }
                if (i < 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
