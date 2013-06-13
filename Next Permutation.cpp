class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        size_t i = num.size() - 1;
        for (; i > 0; --i)
        {
            if (num[i] > num[i-1])
            {
                for (size_t j = num.size() - 1; j >= i; --j)
                {
                    if (num[j] > num[i-1])
                    {
                        swap(num[i-1], num[j]);
                        break;
                    }
                }
                break;
            }
        }
             
        reverse(num.begin() + i, num.end());
    }
};
