class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
        {
            return string("");
        }
         
        size_t longest = strs[0].length();
        for (size_t i = 1; i < strs.size(); ++i)
        {
            if (strs[i].length() < longest)
            {
                longest = strs[i].length();
            }
             
            for (size_t j = 0; j < longest; ++j)
            {
                if (strs[0][j] != strs[i][j])
                {
                    longest = j;
                    break;
                }
            }
        }
         
        return strs[0].substr(0, longest);
    }
};
