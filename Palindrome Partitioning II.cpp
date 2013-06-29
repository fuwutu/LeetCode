class Solution
{
public:
    int minCut(string s)
    {
        const size_t total = s.length();
        vector<size_t> waiting(1, total);
        vector<size_t> temp;
        vector<bool> done(total, false);
        size_t cut = 0;
        while (true)
        {
            for (size_t i = 0; i < waiting.size(); ++i)
            {
                if (isPalindrome(s, total - waiting[i], waiting[i]))
                {
                    return cut;
                }
                
                for (size_t len = 1; len < waiting[i]; ++len)
                {
                    if (!done[len] && isPalindrome(s, total - waiting[i], waiting[i] - len))
                    {
                        temp.push_back(len);
                        done[len] = true;
                    }
                }
            }
            
            waiting.swap(temp);
            temp.clear();
            cut += 1;
        }
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
