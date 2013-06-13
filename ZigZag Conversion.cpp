class Solution
{
public:
    string convert(string s, int nRows)
    {
        if (nRows == 1)
        {
            return s;
        }

        string result;
        int cycle = nRows * 2 - 2;
        for (int i = 0; i < s.length(); i += cycle)
        {
            result.push_back(s[i]);
        }

        int rounds = s.length() / cycle;
        for (int row = 1; row < nRows - 1; ++row)
        {
            int start = 0;
            while (start < s.length())
            {
                if (start + row < s.length())
                {
                    result.push_back(s[start + row]);
                }
                if (start + cycle - row < s.length())
                {
                    result.push_back(s[start + cycle - row]);
                }

                start += cycle;
            }
        }

        for (int i = nRows - 1; i < s.length(); i += cycle)
        {
            result.push_back(s[i]);
        }

        return result;
    }
};
