class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool blocks[9][9] = {false};

        for (size_t r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }
                
                int n = board[r][c] - '1';
                if (rows[r][n] || cols[c][n] || blocks[r / 3 * 3 + c / 3][n])
                {
                    return false;
                }
                
                rows[r][n] = true;
                cols[c][n] = true;
                blocks[r / 3 * 3 + c / 3][n] = true;
            }
        }
        
        return true;
    }
};
