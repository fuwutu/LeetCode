class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        size_t row = grid.size();
        size_t column = grid[0].size();
         
        vector<int> pathsum(column);
         
        pathsum[0] = grid[0][0];
        for (size_t j = 1; j < column; ++j)
        {
            pathsum[j] = grid[0][j] + pathsum[j-1];
        }
         
        for (size_t i = 1; i < row; ++i)
        {
            pathsum[0] += grid[i][0];
            for (size_t j = 1; j < column; ++j)
            {
                pathsum[j] = grid[i][j] + min(pathsum[j-1], pathsum[j]);
            }
        }
         
        return pathsum[column-1];
    }
};
