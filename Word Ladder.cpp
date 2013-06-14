class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        vector<string> reach({start}), temp;
        int step = 1;
        while (!reach.empty() && find(reach.begin(), reach.end(), end) == reach.end())
        {
            step += 1;
            for (auto it = reach.begin(); it != reach.end(); ++it)
            {
                string& s = *it;
                for (size_t i = 0; i < s.length(); ++i)
                {
                    char back = s[i];
                    for (s[i] = 'a'; s[i] <= 'z'; ++s[i])
                        if (s[i] != back && dict.erase(s) == 1)
                            temp.push_back(s);
                    s[i] = back;
                }
            }
            reach.swap(temp);
            temp.clear();
        }
        return find(reach.begin(), reach.end(), end) != reach.end() ? step : 0;
    }
};
