class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        vector<int> s = S;
        sort(s.begin(), s.end());
        
        vector<vector<int> > result;
        result.push_back(vector<int>());
        
        size_t count = 1;
        for (size_t i = 0; i < s.size(); ++i)
        {
            for (size_t j = 0; j < count; ++j)
            {
                result.push_back(result[j]);
                result[count+j].push_back(s[i]);
            }
            count *= 2;
        }
        return result;
    }
};
