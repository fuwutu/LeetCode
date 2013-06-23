class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> parenthesis(n + 1);
        parenthesis[0].push_back("");
        for (int i = 1; i <= n; ++i)
        {
            for (int left = 0; left < i; ++left)
            {
                int right = i - 1 - left;
                for (auto sl : parenthesis[left])
                {
                    for (auto sr : parenthesis[right])
                    {
                        parenthesis[i].push_back("(" + sl + ")" + sr);
                    }
                }
            }
        }
        return parenthesis[n];
    }
};
