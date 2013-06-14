class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() < b.length())
        {
            a.swap(b);
        }
        
        size_t diff = a.length() - b.length();
        string c = a;
        for (size_t i = 0; i < b.length(); ++i)
        {
            c[diff + i] += (b[i] - '0');
        }
        
        for (size_t i = c.length() - 1; i > 0; --i)
        {
            if (c[i] > '1')
            {
                c[i] -= 2;
                c[i - 1] += 1;
            }
        }
        if (c[0] > '1')
        {
            c[0] -= 2;
            c.insert(c.begin(), '1');
        }
        
        return c;
    }
};
