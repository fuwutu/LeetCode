class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int position[128];
        fill(position, position + sizeof(position) / sizeof(position[0]), -1);
        int start = -1;
         
        int result = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            start = max(start, position[s[i]]);
            int len = i - start;
            result = max(result, len);
            position[s[i]] = i;
        }
         
        return result;
    }
};
