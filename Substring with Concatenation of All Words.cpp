class Solution 
{
public:
    void OneWordIn(const string& s, unordered_map<string, int>& word_count, int& not_match)
    {
        auto it = word_count.find(s);
        if (it != word_count.end())
        {
            if (it->second == 0)
            {
                not_match += 1;
            }
            
            it->second += 1;
            
            if (it->second == 0)
            {
                not_match -= 1;
            }
        }
    }
    
    void OneWordOut(const string& s, unordered_map<string, int>& word_count, int& not_match)
    {
        auto it = word_count.find(s);
        if (it != word_count.end())
        {
            if (it->second == 0)
            {
                not_match += 1;
            }
            
            it->second -= 1;
            
            if (it->second == 0)
            {
                not_match -= 1;
            }
        }
    }
    
    vector<int> findSubstring(string S, vector<string> &L)
    {
        const size_t count = L.size();
        const size_t len = L[0].length();

        vector<int> result;
        if (S.length() >= len * L.size())
        {
            unordered_map<string, int> word_count;
            for (size_t i = 0; i < count; ++i)
            {
                string& s = L[i];
                auto ret = word_count.insert(make_pair(s, 1));
                if (!ret.second)
                {
                    ret.first->second += 1;
                }
            }

            int not_match = word_count.size();
            for (size_t start = 0; start < len; ++start)
            {
                if (start + len * count <= S.length())
                {
                    size_t b1 = start;
                    size_t b2 = start;
                    for (size_t i = 0; i < count; ++i)
                    {
                        OneWordOut(S.substr(b2, len), word_count, not_match);
                        b2 += len;
                    }

                    if (not_match == 0)
                    {
                        result.push_back(b1);
                    }

                    while (b2 + len <= S.length())
                    {
                        OneWordIn(S.substr(b1, len), word_count, not_match);
                        b1 += len;

                        OneWordOut(S.substr(b2, len), word_count, not_match);
                        b2 += len;

                        if (not_match == 0)
                        {
                            result.push_back(b1);
                        }
                    }

                    while (b1 + len <= S.length())
                    {
                        OneWordIn(S.substr(b1, len), word_count, not_match);
                        b1 += len;
                    }
                }
            }
        }
        return result;
    }
};
