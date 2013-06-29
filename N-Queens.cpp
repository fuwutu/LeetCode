class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> q;
        for (int i = 0; i < n; ++i)
        {
            q.push_back(vector<int>({i}));
        }
        for (int i = 1; i < n; ++i)
        {
            vector<vector<int>> temp;
            for (vector<int>& x : q)
            {
                for (int p = 0; p < n; ++p)
                {
                    int j = 0;
                    for (; j < i; ++j)
                    {
                        if (x[j] == p || x[j] + j == p + i || x[j] - j == p - i)
                        {
                            break;
                        }
                    }
                    if (j == i)
                    {
                        temp.push_back(x);
                        temp.back().push_back(p);
                    }
                }
            }
            q.swap(temp);
        }

        vector<string> s(n, string(n, '.'));
        for (size_t i = 0; i < n; ++i)
        {
            s[i][i] = 'Q';
        }
        vector<vector<string>> result;
        for (auto& x : q)
        {
            result.push_back(vector<string>());
            for (auto i : x)
            {
                result.back().push_back(s[i]);
            }
        }

        return result;
    }
};
