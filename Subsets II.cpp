class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end());
        vector<vector<int>> result(1, vector<int>());
        for (auto it = S.begin(); it != S.end();)
        {
            auto it2 = it;
            while (it2 != S.end() && *it2 == *it)
            {
                ++it2;
            }
            int value = *it;
            int count = it2 - it;
            it = it2;
            
            size_t s = result.size();
            for (size_t i = 0; i < s; ++i)
            {
                vector<int> subset = result[i];
                for (int c = 0; c < count; ++c)
                {
                    subset.push_back(value);
                    result.push_back(subset);
                }
            }
        }
        return result;
    }
};
