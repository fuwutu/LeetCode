class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int longest = 0;
        vector<int> position_count;
        
        int left = 0;
        int count = 0;
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                ++left;
                position_count.push_back(count);
                count = 0;
            }
            else
            {
                if (left != 0)
                {
                    --left;
                    count += (1 + position_count.back());
                    if (count > longest)
                    {
                        longest = count;
                    }
                    position_count.pop_back();
                }
                else
                {
                    count = 0;
                }
            }
        }
        
        return longest * 2;
    }
};
