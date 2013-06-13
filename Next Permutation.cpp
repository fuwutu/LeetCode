class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        size_t n = num.size();
        
        for (size_t i = n - 1; i > 0; --i)
        {
            if (num[i] > num[i-1])
            {
                for (size_t j = n - 1; j >= i; --j)
                {
                    if (num[j] > num[i-1])
                    {
                        swap(num[i-1], num[j]);
                        reverse(num.begin() + i, num.end());
                        return;
                    }
                }
            }
        }
             
        reverse(num.begin(), num.end());
    }
};
