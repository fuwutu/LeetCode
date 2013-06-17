class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int>> result;
        if (num.size() >= 3)
        {
            sort(num.begin(), num.end());
            for (size_t i = 0; i + 2 < num.size(); ++i)
            {
                size_t j = i + 1;
                size_t k = num.size() - 1;
                while (j < k)
                {
                    int sum = num[i] + num[j] + num[k];
                    if (sum < 0)
                    {
                        ++j;
                    }
                    else if (sum > 0)
                    {
                        --k;
                    }
                    else
                    {
                        result.push_back(vector<int>({num[i], num[j++], num[k--]}));
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
