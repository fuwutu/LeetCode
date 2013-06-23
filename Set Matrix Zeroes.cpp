class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        vector<int> rowshavezero;
        vector<int> columnshavezero;
        
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    rowshavezero.push_back(r);
                    columnshavezero.push_back(c);
                }
            }
        }
        
        for (int r : rowshavezero)
        {
            for (int c = 0; c < columns; ++c)
            {
                matrix[r][c] = 0;
            }
        }
        
        for (int c : columnshavezero)
        {
            for (int r = 0; r < rows; ++r)
            {
                matrix[r][c] = 0;
            }
        }
    }
};

//=============================================================================

class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        bool firstRowHasZero(false);
        bool firstColumnHasZero(false);
        
        for (int c = 0; c < columns; ++c)
        {
            if (matrix[0][c] == 0)
            {
                firstRowHasZero = true;
                break;
            }
        }
        
        for (int r = 0; r < rows; ++r)
        {
            if (matrix[r][0] == 0)
            {
                firstColumnHasZero = true;
            }
        }
        
        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < columns; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        
        for (int c = 1; c < columns; ++c)
        {
            if (matrix[0][c] == 0)
            {
                for (int r = 1; r < rows; ++r)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        
        for (int r = 1; r < rows; ++r)
        {
            if (matrix[r][0] == 0)
            {
                for (int c = 1; c < columns; ++c)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        
        if (firstRowHasZero)
        {
            for (int c = 0; c < columns; ++c)
            {
                matrix[0][c] = 0;
            }
        }
        
        if (firstColumnHasZero)
        {
            for (int r = 0; r < rows; ++r)
            {
                matrix[r][0] = 0;
            }
        }
    }
};
