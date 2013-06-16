class Solution
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
