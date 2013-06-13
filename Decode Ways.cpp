class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        
        if (s[0] == '0')
        {
            return 0;
        }
        
        int a = 1;
        int b = 1;
        
        for (size_t i = 1; i < s.length(); ++i)
        {
            int c = 0;

            int two_digit_value = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (two_digit_value >= 10 && two_digit_value <= 26)
            {
                c += a;
            }
            
            if (s[i] > '0')
            {
                c += b;
            }
            
            a = b;
            b = c;
            
            if (b == 0)
            {
                break;
            }
        }
        
        return b;
    }
};
