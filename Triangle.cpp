class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        vector<int> pathsum(triangle.size());
        vector<int> temp(triangle.size());
        pathsum[0] = triangle[0][0];
        for (size_t i = 1; i < triangle.size(); ++i)
        {
            pathsum.swap(temp);
            pathsum[0] = temp[0] + triangle[i][0];
            pathsum[i] = temp[i-1] + triangle[i][i];
            for (size_t j = 1; j < i; ++j)
            {
                pathsum[j] = triangle[i][j] + min(temp[j-1], temp[j]);
            }
        }
        return *min_element(pathsum.begin(), pathsum.end());
    }
};
