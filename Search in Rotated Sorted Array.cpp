class Solution
{
public:
    int search(int A[], int n, int target)
    {
        if (n == 0)
        {
            return -1;
        }
        
        if (n == 1)
        {
            return A[0] == target ? 0 : -1;
        }
        
        if (A[0] < A[n-1])
        {
            return search(A, 0, n, target);
        }
        
        int left = 1;
        int right = n;
        int middle;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (A[middle] > A[0])
            {
                left = middle + 1;
            }
            else if (A[middle] > A[middle - 1])
            {
                right = middle;
            }
            else
            {
                break;
            }
        }
        
        if (target >= A[0])
        {
            return search(A, 0, middle, target);
        }
        else
        {
            return search(A, middle, n, target);
        }
    }
    
    int search(int A[], int start, int end, int target)
    {
        while (start < end)
        {
            int middle = (start + end) / 2;
            if (A[middle] < target)
            {
                start = middle + 1;
            }
            else if (A[middle] > target)
            {
                end = middle;
            }
            else
            {
                return middle;
            }
        }
        
        return -1;
    }
};
