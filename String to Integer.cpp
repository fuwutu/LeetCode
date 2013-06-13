class Solution
{
public:
    int atoi(const char *str)
    {
        int result = 0;
        bool negative = false;
         
        while (isspace(*str))
        {
            ++str;
        }
         
        if (*str == '+')
        {
            negative = false;
            ++str;
        }
        else if (*str == '-')
        {
            negative = true;
            ++str;
        }
         
        if (negative)
        {
            while (isdigit(*str))
            {
                int n = *str - '0';
                 
                if (result < std::numeric_limits<int>::min() / 10)
                {
                    result = std::numeric_limits<int>::min();
                    break;
                }
                result *= 10;
                 
                if (result < std::numeric_limits<int>::min() + n)
                {
                    result = std::numeric_limits<int>::min();
                    break;
                }
                result -= n;
                 
                ++str;
            }
        }
        else
        {
            while (isdigit(*str))
            {
                int n = *str - '0';
                 
                if (result > std::numeric_limits<int>::max() / 10)
                {
                    result = std::numeric_limits<int>::max();
                    break;
                }
                result *= 10;
                 
                if (result > std::numeric_limits<int>::max() - n)
                {
                    result = std::numeric_limits<int>::max();
                    break;
                }
                result += n;
                 
                ++str;
            }
        }
         
        return result;
    }
};
