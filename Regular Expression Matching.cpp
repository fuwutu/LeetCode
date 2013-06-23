class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        set<char*> match({const_cast<char*>(s)});
        set<char*> temp;
        while (*p != '\0' && !match.empty())
        {
            if (p[0] == '.')
            {
                if (p[1] == '*')
                {
                    auto m = *(match.begin());
                    temp.insert(m);
                    while (*m != '\0')
                    {
                        temp.insert(++m);
                    }
                    p = p + 2;
                }
                else
                {
                    for (char* m : match)
                    {
                        if (*m != '\0')
                        {
                            temp.insert(m + 1);
                        }
                    }
                    p = p + 1;
                }
            }
            else
            {
                if (p[1] == '*')
                {
                    for (char* m : match)
                    {
                        temp.insert(m);
                        while (*m == *p)
                        {
                            temp.insert(++m);
                        }
                    }
                    p = p + 2;
                }
                else
                {
                    for (char* m : match)
                    {
                        if (*m == *p)
                        {
                            temp.insert(m + 1);
                        }
                    }
                    p = p + 1;
                }
            }
            
            match.swap(temp);
            temp.clear();
        }
        
        return (!match.empty() && *(*(match.rbegin())) == '\0');
    }
};
