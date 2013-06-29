class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if (!matrix.empty())
        {
            int top = 0;
            int bottom = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
            while (true)
            {
                for (int c = left; c <= right; ++c)
                {
                    result.push_back(matrix[top][c]);
                }
                top += 1;
                if (top > bottom)
                {
                    break;
                }
                
                for (int r = top; r <= bottom; ++r)
                {
                    result.push_back(matrix[r][right]);
                }
                right -= 1;
                if (left > right)
                {
                    break;
                }
                
                for (int c = right; c >= left; --c)
                {
                    result.push_back(matrix[bottom][c]);
                }
                bottom -= 1;
                if (top > bottom)
                {
                    break;
                }
                
                for (int r = bottom; r >= top; --r)
                {
                    result.push_back(matrix[r][left]);
                }
                left += 1;
                if (left > right)
                {
                    break;
                }
            }
        }
        return result;
    }
};
