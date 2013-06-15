class Solution
{
public:
    void search_next_reach(unordered_set<string>& reach, const unordered_set<string>& other_reach, unordered_set<string>& meet, unordered_map<string, vector<string>>& path, unordered_set<string>& dict)
    {
        unordered_set<string> temp;
        reach.swap(temp);

        for (auto it = temp.begin(); it != temp.end(); ++it)
        {
            string s = *it;
            for (size_t i = 0; i < s.length(); ++i)
            {
                char back = s[i];
                for (s[i] = 'a'; s[i] <= 'z'; ++s[i])
                {
                    if (s[i] != back)
                    {
                        if (reach.count(s) == 1)
                        {
                            path[s].push_back(*it);
                        }
                        else if (dict.erase(s) == 1)
                        {
                            path[s].push_back(*it);
                            reach.insert(s);
                        }
                        else if (other_reach.count(s) == 1)
                        {
                            path[s].push_back(*it);
                            reach.insert(s);
                            meet.insert(s);
                        }
                    }
                }
                s[i] = back;
            }
        }
    }

    void walk(vector<vector<string>>& all_path, unordered_map<string, vector<string>> kids)
    {
        vector<vector<string>> temp;
        while (!kids[all_path.back().back()].empty())
        {
            all_path.swap(temp);
            all_path.clear();
            for (auto it = temp.begin(); it != temp.end(); ++it)
            {
                vector<string>& one_path = *it;
                vector<string>& p = kids[one_path.back()];
                for (size_t i = 0; i < p.size(); ++i)
                {
                    all_path.push_back(one_path);
                    all_path.back().push_back(p[i]);
                }
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string>& dict)
    {
        vector<vector<string>> result, result_temp;
        if (dict.erase(start) == 1 && dict.erase(end) == 1) 
        {
            unordered_map<string, vector<string>> kids_from_start;
            unordered_map<string, vector<string>> kids_from_end;

            unordered_set<string> reach_start({start});
            unordered_set<string> reach_end({end});

            unordered_set<string> meet;
            while (meet.empty() && !reach_start.empty() && !reach_end.empty())
            {
                if (reach_start.size() < reach_end.size())
                {
                    search_next_reach(reach_start, reach_end, meet, kids_from_start, dict);
                }
                else
                {
                    search_next_reach(reach_end, reach_start, meet, kids_from_end, dict);
                }
            }

            if (!meet.empty())
            {
                for (auto it = meet.begin(); it != meet.end(); ++it)
                {
                    result.push_back({*it});
                }

                walk(result, kids_from_start);
                for (size_t i = 0; i < result.size(); ++i)
                {
                    reverse(result[i].begin(), result[i].end());
                }
                walk(result, kids_from_end);
            }
        }
        
        return result;
    }
};
