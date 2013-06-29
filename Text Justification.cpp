class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int L)
    {
        vector<string> result;
        
        size_t begin = 0;
        size_t end = 0;
        while (end < words.size())
        {
            size_t total = words[end].size();
            end += 1;

            while (end < words.size() && total + (end - begin) + words[end].size() <= L)
            {
                total += words[end].size();
                end += 1;
            }
            
            string line(words[begin]);
            size_t count = end - begin;
            if (end < words.size())
            {
                if (count > 1)
                {
                    size_t space = (L - total) / (count - 1);
                    size_t m = (L - total) % (count - 1);
                    for (size_t i = 1; i < count; ++i)
                    {
                        if (i <= m)
                        {
                            line.append(space + 1, ' ');
                        }
                        else
                        {
                            line.append(space, ' ');
                        }
                        line.append(words[begin + i]);
                    };
                }
                else
                {
                    line.append(L - total, ' ');
                }
            }
            else
            {
                for (size_t i = begin + 1; i < end; ++i)
                {
                    line.append(1, ' ');
                    line.append(words[i]);
                }
                line.append(L - total - (count - 1), ' ');
            }
            result.push_back(line);
            
            begin = end;
        }

        return result;
    }
};
