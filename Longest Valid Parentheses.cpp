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
                --left;
                if (left != -1)
                {
                    count += 1;
                    count += position_count.back();
                    if (count > longest)
                    {
                        longest = count;
                    }
                    position_count.pop_back();
                }
                else
                {
                    left = 0;
                    count = 0;
                    position_count.clear();
                }
            }
        }
        
        return longest * 2;
    }
};

//=============================================================================

class Solution2
{
public:
    int longestValidParentheses(string s)
    {
        int length = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                int continuous_left = 1;
                for (int j = i + 1; j < s.length(); ++j)
                {
                    if (s[j] == '(')
                    {
                        ++continuous_left;
                    }
                    else
                    {
                        break;
                    }
                }

                int last_valid_j = 0;
                int count = continuous_left;
                int min_count = count;
                for (int j = i + continuous_left; j < s.length(); ++j)
                {
                    if (s[j] == '(')
                    {
                        count += 1;
                    }
                    else
                    {
                        count -= 1;

                        if (count == 0)
                        {
                            last_valid_j = j;
                            if (j + 1 - i > length)
                            {
                                length = j + 1 - i;
                            }
                        }
                        
                        if (count < 0)
                        {
                            break;
                        }

                        if (count < min_count)
                        {
                            min_count = count;
                        }
                    }
                }
                
                if (last_valid_j != 0)
                {
                    i = last_valid_j;
                }
                else
                {
                    i = i + min_count - 1;
                }
            }
        }
        
        return length;
    }
};
