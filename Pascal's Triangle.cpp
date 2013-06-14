class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > result;
        vector<int> v;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = i - 1; j >= 1; --j)
            {
                v[j] += v[j-1];
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result;
    }
};
