class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            v.push_back(A[i]);
        }
        auto lower = lower_bound(v.begin(), v.end(), target);
        auto upper = upper_bound(v.begin(), v.end(), target);
        
        if (lower == v.end() || *lower != target)
        {
            return vector<int>({-1, -1});
        }
        else
        {
            return vector<int>({lower - v.begin(), upper - v.begin() - 1});
        }
    }
};

class Solution2
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        int left = 0;
        int right = n;
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (A[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        
        if (left >= 0 && left < n && A[left] == target)
        {
            int lowerbound = left;
            right = n;
            while (left < right)
            {
                int middle = (left + right) / 2;
                if (A[middle] <= target)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle;
                }
            }
            int upperbound = left - 1;
            return vector<int>({lowerbound, upperbound});
        }
        else
        {
            return vector<int>({-1, -1});
        }
    }
};
