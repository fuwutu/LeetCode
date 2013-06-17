class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        int closest = 0;
        if (num.size() >= 3)
        {
            sort(num.begin(), num.end());
            closest = num[0] + num[1] + num[2];
            for (size_t i = 0; i + 2 < num.size(); ++i)
            {
                size_t j = i + 1;
                size_t k = num.size() - 1;
                while (j < k)
                {
                    int sum = num[i] + num[j] + num[k];
                    if (abs(sum - target) < abs(closest - target))
                    {
                        closest = sum;
                    }
                    
                    if (sum < target)
                    {
                        ++j;
                    }
                    else if (sum > target)
                    {
                        --k;
                    }
                    else
                    {
                        ++j;
                        --k;
                    }
                }
            }
        }
        
        return closest;
    }
};
