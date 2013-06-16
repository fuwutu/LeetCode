class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        int length = 0;
        int last_length = 0;
        while (true)
        {
            if (isalpha(*s))
            {
                ++length;
            }
            else
            {
                if (length != 0)
                {
                    last_length = length;
                    length = 0;
                }
                
                if (*s == '\0')
                {
                    break;
                }
            }
            
            ++s;
        }
        
        return last_length;
    }
};
