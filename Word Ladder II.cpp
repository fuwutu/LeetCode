class Solution
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<vector<string>> result, result_temp;
        if (dict.count(start) == 1 && dict.count(end) == 1)
        {
            unordered_set<string> step_reach({start});
            unordered_set<string> step_reach_temp;
            dict.erase(start);
            unordered_map<string, vector<string>> parents;
            while (!step_reach.empty() && parents[end].empty())
            {
                step_reach.swap(step_reach_temp);
                step_reach.clear();
                for (auto it = step_reach_temp.begin(); it != step_reach_temp.end(); ++it)
                {
                    string s = *it;
                    for (size_t i = 0; i < s.length(); ++i)
                    {
                        char c = s[i];
                        for (s[i] = 'a'; s[i] <= 'z'; ++s[i])
                        {
                            if (s[i] != c)
                            {
                                if (dict.erase(s) == 1)
                                {
                                    step_reach.insert(s);
                                    parents[s].push_back(*it);
                                }
                                else
                                {
                                    if (step_reach.count(s) == 1)
                                    {
                                        parents[s].push_back(*it);
                                    }
                                }
                            }
                        }
                        s[i] = c;
                    }
                }
            }
            
            if (!parents[end].empty())
            {
                result.push_back({end});
                while (true)
                {
                    result.swap(result_temp);
                    result.clear();
                    for (auto it = result_temp.begin(); it != result_temp.end(); ++it)
                    {
                        vector<string>& path = *it;
                        vector<string>& p = parents[path.back()];
                        for (size_t i = 0; i < p.size(); ++i)
                        {
                            result.push_back(path);
                            result.back().push_back(p[i]);
                        }
                    }
                    if (result.back().back() == start)
                    {
                        for (size_t i = 0; i < result.size(); ++i)
                        {
                            reverse(result[i].begin(), result[i].end());
                        }
                        break;
                    }
                }
            }
        }
        
        return result;
    }
};
