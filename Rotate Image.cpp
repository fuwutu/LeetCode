class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        size_t n = matrix.size();
        for (size_t i = 0; i < (n + 1) / 2; ++i)
        {
            for (size_t j = 0; j < n / 2; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
