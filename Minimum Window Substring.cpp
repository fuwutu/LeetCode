class Solution
{
public:
    string minWindow(string S, string T)
    {
        string result;
        
        vector<int> lettercount(256, 0);
        for (char c : T)
        {
            lettercount[c] -= 1;
        }
        
        int not_contain = lettercount.size() - count(lettercount.begin(), lettercount.end(), 0);
        
        size_t left = 0;
        size_t right = 0;
        for (; right < S.size(); right += 1)
        {
            lettercount[S[right]] += 1;
            if (lettercount[S[right]] == 0)
            {
                not_contain -= 1;
                if (not_contain == 0)
                {
                    while (lettercount[S[left]] > 0)
                    {
                        lettercount[S[left]] -= 1;
                        left += 1;
                    }
                    result.assign(S, left, right + 1 - left);
                    break;
                }
            }
        }
        
        while (right < S.size())
        {
            right += 1;
            lettercount[S[right]] += 1;
            while (lettercount[S[left]] > 0)
            {
                lettercount[S[left]] -= 1;
                left += 1;
            }
            if (right + 1 - left < result.size())
            {
                result.assign(S, left, right + 1 - left);
            }
        }
        
        return result;
    }
};
