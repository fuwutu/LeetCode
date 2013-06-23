class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        sort(num.begin(), num.end());
        
        if (num.size() >= 4)
        {
            size_t left = 4;
            for (size_t right = 4; right < num.size(); ++right)
            {
                if (num[right] != num[right - 1] || num[right] != num[right - 2] || num[right] != num[right - 3] || num[right] != num[right - 4])
                {
                    num[left++] = num[right];
                }
            }
            num.erase(num.begin() + left, num.end());
        }
        
        vector<vector<int>> result;
        vector<int> four(4);
        for (size_t c = 2; c < num.size(); ++c)
        {
            for (size_t d = c + 1; d < num.size(); ++d)
            {
                int sum2 = num[c] + num[d];
                size_t a = 0, b = c - 1;
                while (a < b)
                {
                    int sum4 = sum2 + num[a] + num[b];
                    if (sum4 < target)
                    {
                        ++a;
                    }
                    else if (sum4 > target)
                    {
                        --b;
                    }
                    else
                    {
                        four[0] = num[a];
                        four[1] = num[b];
                        four[2] = num[c];
                        four[3] = num[d];
                        result.push_back(four);
                        ++a;
                        --b;
                    }
                }
            }
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
