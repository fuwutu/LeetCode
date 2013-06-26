class Solution
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> msvs;
        for (auto s : strs)
        {
            string r = s;
            sort(r.begin(), r.end());
            msvs[r].push_back(s);
        }
        
        vector<string> result;
        for (auto p : msvs)
        {
            if (p.second.size() > 1)
            {
                for (auto s : p.second)
                {
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};
