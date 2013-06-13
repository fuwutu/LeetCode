class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                    return result;
                }
            }
        }
    }
};
