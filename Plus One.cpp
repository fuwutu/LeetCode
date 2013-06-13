class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result = digits;
        result[result.size() - 1] += 1;
        for (size_t i = result.size() - 1; i > 0; --i)
        {
            if (result[i] == 10)
            {
                result[i] = 0;
                result[i-1] += 1;
            }
        }
        if (result[0] == 10)
        {
            result[0] = 0;
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
