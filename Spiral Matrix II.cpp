class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int start = 1;
        int count = n - 1;
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < count; ++j)
            {
                matrix[i][i+j] = start + j;
                matrix[i+j][n-1-i] = matrix[i][i+j] + count;
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i] + count;
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j] + count;
            }
            start += count * 4;
            count -= 2;
        }
        
        if (n % 2 == 1)
        {
            matrix[n/2][n/2] = start;
        }
        
        return matrix;
    }
};
