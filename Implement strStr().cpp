class Solution
{
public:
    char *strStr(char *haystack, char *needle)
    {
        if (*needle == 0)
        {
            return haystack;
        }
        
        int hlen = strlen(haystack);
        int nlen = strlen(needle);

        vector<int> next(nlen + 1);
        next[1] = next[0] = 0;
        int k = 0;
        for (int i = 2; i <= nlen; ++i)
        {
            for (; k != 0 && needle[k] != needle[i-1]; k = next[k])
                nullptr;
            if (needle[k] == needle[i-1])
                k++;
            next[i] = k;
        }

        int hi = 0, ni = 0;
        while (hi < hlen)
        {
            for (ni = next[ni]; ni < nlen && needle[ni] == haystack[hi]; ni++, hi++)
                nullptr;
            if (ni == 0)
                hi++;
            else if (ni == nlen)
            {
                return haystack + hi - nlen;
            }
        }

        return nullptr;
    }
};
