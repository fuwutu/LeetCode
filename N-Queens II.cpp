
class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<int> rowpos(n);
        int count = 0;
        dps(rowpos, 0, count);
        return count;
    }

    void dps(vector<int>& rowpos, int row, int& count)
    {
        int n = rowpos.size();
        for (int p = 0; p < n; ++p)
        {
            int i = 0;
            for (; i < row; ++i)
            {
                if (rowpos[i] == p || rowpos[i] + i == p + row || rowpos[i] - i == p - row)
                {
                    break;
                }
            }
            if (i == row)
            {
                rowpos[row] = p;
                if (row < n - 1)
                {
                    dps(rowpos, row + 1, count);
                }
                else
                {
                    count += 1;
                }
            }
        }
    }
};
