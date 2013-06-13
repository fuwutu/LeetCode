class Solution
{
public:
    int romanToInt(string s)
    {
        const string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        const string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string thousand[] = {"", "M", "MM", "MMM"};
         
        int num = 0;
        for (size_t i = sizeof(thousand) / sizeof(thousand[0]) - 1; i > 0; --i)
        {
            size_t len = thousand[i].length();
            if (s.length() >= len && s.substr(0, len) == thousand[i])
            {
                num += i * 1000;
                s.erase(0, len);
                break;
            }
        }
         
        for (size_t i = sizeof(hundred) / sizeof(hundred[0]) - 1; i > 0; --i)
        {
            size_t len = hundred[i].length();
            if (s.length() >= len && s.substr(0, len) == hundred[i])
            {
                num += i * 100;
                s.erase(0, len);
                break;
            }
        }
         
        for (size_t i = sizeof(ten) / sizeof(ten[0]) - 1; i > 0; --i)
        {
            size_t len = ten[i].length();
            if (s.length() >= len && s.substr(0, len) == ten[i])
            {
                num += i * 10;
                s.erase(0, len);
                break;
            }
        }
         
        for (size_t i = sizeof(one) / sizeof(one[0]) - 1; i > 0; --i)
        {
            size_t len = one[i].length();
            if (s.length() >= len && s.substr(0, len) == one[i])
            {
                num += i * 1;
                s.erase(0, len);
                break;
            }
        }
         
        return num;
    }
};
