class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int bit3[21] = {0};
        for (int i = 0; i < n; ++i)
        {
            unsigned x(static_cast<unsigned>(A[i])), k(0);
            while (x != 0)
            {
                bit3[k] += x % 3;
                x /= 3;
                k += 1;
            }
        }
        unsigned answer = 0;
        for (int i = sizeof(bit3) / sizeof(bit3[0]); i >= 0; --i)
        {
            answer = answer * 3 + bit3[i] % 3;
        }
        return static_cast<int>(answer);
    }
};
