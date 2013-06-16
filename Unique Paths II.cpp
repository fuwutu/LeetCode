class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        const int row = obstacleGrid.size();
        const int column = obstacleGrid[0].size();
        
        vector<int> path(obstacleGrid[0].size(), 1);
        if (obstacleGrid[0][0] == 1)
        {
            path[0] = 0;
        }
        for (size_t c = 1; c < column; ++c)
        {
            if (obstacleGrid[0][c] == 1 || path[c - 1] == 0)
            {
                path[c] = 0;
            }
        }
        
        for (size_t r = 1; r < row; ++r)
        {
            if (obstacleGrid[r][0] == 1)
            {
                path[0] = 0;
            }
            for (size_t c = 1; c < column; ++c)
            {
                if (obstacleGrid[r][c] == 1)
                {
                    path[c] = 0;
                }
                else
                {
                    path[c] += path[c - 1];
                }
            }
        }
        
        return path.back();
    }
};
