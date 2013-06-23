class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if(!s && !p) return true;
        
        const char *star_p=NULL, *star_s=NULL;
        
        while(*s)
        {
            if(*p == '?' || *p == *s)
            {
                ++p,++s;
            }
            else if(*p == '*')
            {
                while(*p == '*')
                {
                    ++p;
                }
                
                if(!*p) return true;
                
                star_p = p;
                star_s = s;
            }
            else if ((!*p || *p != *s)  && star_p)
            {
                s = ++star_s;
                p = star_p;
            }
            else
            {
                return false;
            }
        }
        
        while (*p)
        {
            if(*p++ != '*')
            {
                return false;
            }
        }

        return true;
    }
};
