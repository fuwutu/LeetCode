class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t slen = s.length();
        
        string result;
        size_t maxlen = 0;
        
        for (size_t sum = 0; sum <= (slen - 1) * 2; ++sum)
        {
            size_t count = 0;
            size_t i = (sum + 1) / 2;
            for (; i <= min(slen - 1, sum); ++i)
            {
                if (s[i] != s[sum - i])
                {
                    break;
                }
                ++count;
            }
            
            size_t len = count * 2 - ((sum + 1) % 2);
            if (len > maxlen)
            {
                result = s.substr((sum + 1 - len) / 2, len);
                maxlen = len;
            }
        }
        
        return result;
    }
};
