class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.empty() || board[0].empty())
        {
            return ;
        }
        
        size_t rows = board.size();
        size_t columns = board[0].size();
        
        for (size_t c = 0; c < columns; ++c)
        {
            if (board[0][c] == 'O')
            {
                changeO2T(board, 0, c);
            }
            if (board[rows - 1][c] == 'O')
            {
                changeO2T(board, rows - 1, c);
            }
        }
        
        for (size_t r = 0; r < columns; ++r)
        {
            if (board[r][0] == 'O')
            {
                changeO2T(board, r, 0);
            }
            if (board[r][columns - 1] == 'O')
            {
                changeO2T(board, r, columns - 1);
            }
        }
        
        for (size_t r = 0; r < rows; ++r)
        {
            for (size_t c = 0; c < columns; ++c)
            {
                if (board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
            }
        }
        
        for (size_t r = 0; r < rows; ++r)
        {
            for (size_t c = 0; c < columns; ++c)
            {
                if (board[r][c] == 'T')
                {
                    board[r][c] = 'O';
                }
            }
        }
    }
    
    void changeO2T(vector<vector<char>>& board, size_t row, size_t column)
    {
        board[row][column] = 'T';
        
        if (row > 0 && board[row - 1][column] == 'O')
        {
            changeO2T(board, row - 1, column);
        }
        if (row + 1 < board.size() && board[row + 1][column] == 'O')
        {
            changeO2T(board, row + 1, column);
        }
        if (column > 0 && board[row][column - 1] == 'O')
        {
            changeO2T(board, row, column - 1);
        }
        if (column + 1 < board[0].size() && board[row][column + 1] == 'O')
        {
            changeO2T(board, row, column + 1);
        }
    }
};
