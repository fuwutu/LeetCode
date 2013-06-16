class Solution
{
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<int> one(num);
        vector<vector<int>> all({one});
        
        vector<int> p;
        for (size_t i = 0; i < num.size(); ++i)
        {
            p.push_back(i);
        }
        
        while (next_permutation(p.begin(), p.end()))
        {
            for (size_t i = 0; i < num.size(); ++i)
            {
                one[i] = num[p[i]];
            }
            all.push_back(one);
        }
        
        return all;
    }
};
