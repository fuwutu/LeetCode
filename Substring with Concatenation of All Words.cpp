class Solution 
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        const size_t count = L.size();
        const size_t len = L[0].length();

        vector<int> result;
        if (S.length() >= len * L.size())
        {
            unordered_map<string, int> string_count;
            for (size_t i = 0; i < count; ++i)
            {
                string& s = L[i];
                auto ret = string_count.insert(make_pair(s, 1));
                if (!ret.second)
                {
                    ret.first->second += 1;
                }
            }

            int not_match = string_count.size();
            for (size_t start = 0; start < len; ++start)
            {
                if (start + len * count <= S.length())
                {
                    size_t b1 = start;
                    size_t b2 = start;
                    for (size_t i = 0; i < count; ++i)
                    {
                        string s2 = S.substr(b2, len);
                        auto it2 = string_count.find(s2);
                        if (it2 != string_count.end())
                        {
                            it2->second -= 1;
                            if (it2->second == 0)
                            {
                                not_match -= 1;
                            }
                            if (it2->second == -1)
                            {
                                not_match += 1;
                            }
                        }
                        b2 += len;
                    }

                    if (not_match == 0)
                    {
                        result.push_back(b1);
                    }

                    while (b2 + len <= S.length())
                    {
                        string s1 = S.substr(b1, len);
                        auto it1 = string_count.find(s1);
                        if (it1 != string_count.end())
                        {
                            it1->second += 1;
                            if (it1->second == 0)
                            {
                                not_match -= 1;
                            }
                            if (it1->second == 1)
                            {
                                not_match += 1;
                            }
                        }
                        b1 += len;

                        string s2 = S.substr(b2, len);
                        auto it2 = string_count.find(s2);
                        if (it2 != string_count.end())
                        {
                            it2->second -= 1;
                            if (it2->second == 0)
                            {
                                not_match -= 1;
                            }
                            if (it2->second == -1)
                            {
                                not_match += 1;
                            }
                        }
                        b2 += len;

                        if (not_match == 0)
                        {
                            result.push_back(b1);
                        }
                    }

                    while (b1 + len <= S.length())
                    {
                        string s1 = S.substr(b1, len);
                        auto it1 = string_count.find(s1);
                        if (it1 != string_count.end())
                        {
                            it1->second += 1;
                            if (it1->second == 0)
                            {
                                not_match -= 1;
                            }
                            if (it1->second == 1)
                            {
                                not_match += 1;
                            }
                        }
                        b1 += len;
                    }
                }
            }
        }
        return result;
    }
};
