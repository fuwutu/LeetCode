class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<vector<string>> partition_string({{s}});
        vector<vector<string>> temp;
        while (!partition_string.empty())
        {
            for (auto& x : partition_string)
            {
                string& untreated = x.back();
                for (size_t len = 1; len < untreated.size(); ++len)
                {
                    if (isPalindrome(untreated, 0, len))
                    {
                        temp.push_back(x);
                        temp.back().back().erase(len, untreated.size() - len);
                        temp.back().push_back(untreated.substr(len, untreated.size() - len));
                    }
                }

                if (isPalindrome(untreated, 0, untreated.size()))
                {
                    result.push_back(x);
                }
            }

            partition_string.swap(temp);
            temp.clear();
        }

        return result;
    }

    bool isPalindrome(const string& s, size_t begin, size_t len)
    {
        for (size_t i = 0; i < len / 2; ++i)
        {
            if (s[begin + i] != s[begin + len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
