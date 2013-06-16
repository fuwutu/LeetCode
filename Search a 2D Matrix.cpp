class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        const int row = matrix.size();
        const int column = matrix[0].size();
        int left = 0;
        int right = row * column;
        while (left < right)
        {
            int middle = (left + right) / 2;
            int value = matrix[middle / column][middle % column];
            if (value == target)
            {
                return true;
            }
            if (value < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return false;
    }
};
