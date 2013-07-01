class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        
        if (rows * cols < word.size())
            return false;

        for (size_t r = 0; r < rows; ++r)
            for (size_t c = 0; c < cols; ++c)
                if (board[r][c] == word[0])
                    if (dfs(board, r, c, word, 1))
                        return true;

        return false;
    }

    bool dfs(vector<vector<char>>& board, size_t row, size_t col, string& word, size_t pos)
    {
        if (pos == word.size())
            return true;

        board[row][col] = 0;
        if (row > 0 && board[row - 1][col] == word[pos] && dfs(board, row - 1, col, word, pos + 1)
            || col > 0 && board[row][col - 1] == word[pos] && dfs(board, row, col - 1, word, pos + 1)
            || row + 1 < rows && board[row + 1][col] == word[pos] && dfs(board, row + 1, col, word, pos + 1)
            || col + 1 < cols && board[row][col + 1] == word[pos] && dfs(board, row, col + 1, word, pos + 1))
        {
            return true;
        }
        board[row][col] = word[pos - 1];

        return false;
    }

private:
    size_t rows;
    size_t cols;
};
