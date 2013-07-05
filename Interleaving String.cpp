class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        
        vector<bool> match(s1.size() + 1, false);
        match[0] = true;
        
        for (size_t c3 = 1; c3 <= s2.size(); ++c3)
        {
            for (size_t c1 = min(s1.size(), c3); c1 >= 1; --c1)
            {
                match[c1] = (match[c1-1] && s1[c1-1] == s3[c3-1] || match[c1] && c1 < c3 && s2[c3-c1-1] == s3[c3-1]);
            }
            match[0] = (match[0] && s2[c3-1] == s3[c3-1]);
        }
        
        for (size_t c3 = s2.size() + 1; c3 <= s3.size(); ++c3)
        {
            for (size_t c1 = min(s1.size(), c3); c1 >= c3 - s2.size() ; --c1)
            {
                match[c1] = match[c1-1] && s1[c1-1] == s3[c3-1] || match[c1] && c1 < c3 && s2[c3-c1-1] == s3[c3-1];
            }
        }
        
        return match[s1.size()];
    }
};
