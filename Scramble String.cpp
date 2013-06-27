class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        
        if (s1 == s2)
        {
            return true;
        }
        
        string r1 = s1;
        sort(r1.begin(), r1.end());
        
        string r2 = s2;
        sort(r2.begin(), r2.end());
        
        if (r1 != r2)
        {
            return false;
        }
        
        for (size_t n = 1; n < s1.length(); ++n)
        {
            if (isScramble(s1.substr(0, n), s2.substr(0, n))
                && isScramble(s1.substr(n, s1.length() - n), s2.substr(n, s2.length() - n)))
            {
                return true;
            }
            
            if (isScramble(s1.substr(0, n), s2.substr(s2.length() - n, n))
                && isScramble(s1.substr(n, s1.length() - n), s2.substr(0, s2.length() - n)))
            {
                return true;
            }
        }
        
        return false;
    }
};
