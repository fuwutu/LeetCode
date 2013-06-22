class Solution 
{
public:
    int longestConsecutive(vector<int> &num)
    {
        unordered_set<int> us;
        for (auto x : num)
        {
            us.insert(x);
        }
        
        int longest = 0;
        for (auto x: num)
        {
            auto it = us.find(x);
            if (it != us.end())
            {
                us.erase(it);
                
                int small = x - 1;
                while (true)
                {
                    it = us.find(small);
                    if (it == us.end())
                    {
                        break;
                    }
                    us.erase(it);
                    small -= 1;
                }
                
                int big = x + 1;
                while (true)
                {
                    it = us.find(big);
                    if (it == us.end())
                    {
                        break;
                    }
                    us.erase(it);
                    big += 1;
                }
                
                int length = big - small - 1;
                if (length > longest)
                {
                    longest = length;
                }
            }
        }
        return longest;
    }
};
