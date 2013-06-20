class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        string b;
        for (int i = 1; i < n; ++i)
        {
            for (size_t i = 0; i < s.length(); )
            {
                size_t j = i + 1;
                while (j < s.length() && s[j] == s[i])
                {
                    ++j;
                }
                b.append(1, static_cast<char>('0' + (j - i)));
                b.append(1, s[i]);
                i = j;
            }
            s.swap(b);
            b.clear();
        }
        return s;
    }
};
