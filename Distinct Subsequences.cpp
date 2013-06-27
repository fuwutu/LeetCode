class Solution
{
public:
    int numDistinct(string S, string T)
    {
        int num = 0;
        if (S.length() >= T.length() && !T.empty())
        {
            vector<int> d(S.length(), 0);
            if (S[0] == T[0])
            {
                d[0] = 1;
            }
            for (size_t i = 1; i < S.length(); ++i)
            {
                if (S[i] == T[0])
                {
                    d[i] = d[i-1] + 1;
                }
                else
                {
                    d[i] = d[i-1];
                }
            }
            
            for (size_t k = 1; k < T.length(); ++k)
            {
                vector<int> temp(S.length(), 0);
                d.swap(temp);
                
                for (size_t i = k; i + (T.length() - 1 - k) < S.length(); ++i)
                {
                    if (S[i] == T[k])
                    {
                        d[i] = d[i-1] + temp[i-1];
                    }
                    else
                    {
                        d[i] = d[i-1];
                    }
                }
            }
            num = d.back();
        }
        
        return num;
    }
};
