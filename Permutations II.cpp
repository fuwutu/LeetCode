class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<int> one(num);
        sort(one.begin(), one.end());
        vector<vector<int>> all({one});

        const size_t count = one.size();
        while (true)
        {
            bool find = false;
            for (size_t i = count - 1; i > 0; --i)
            {
                if (one[i] > one[i-1])
                {
                    size_t j = count - 1;
                    while (one[j] <= one[i - 1])
                    {
                        --j;
                    }

                    swap(one[i - 1], one[j]);
                    reverse(one.begin() + i, one.end());
                    all.push_back(one);
                    
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                break;
            }
        }
        
        return all;
    }
};
