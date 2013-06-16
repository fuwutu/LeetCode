class Solution
{
public:
    int GCD(int m, int n)
    {
        if (m < n)
        {
            swap(m, n);
        }
        
        int r = m % n;
        while (r != 0)
        {
            m = n;
            n = r;
            r = m % n;
        }
        
        return n;
    }
    
    int uniquePaths(int m, int n)
    {   
        m -= 1;
        n -= 1;
        
        int total = 1;
        for (int i = 0; i < min(m, n); ++i)
        {
            int gcd = GCD(m + n - i, i + 1);
            total /= ((i + 1) / gcd);
            total *= ((m + n - i) / gcd);
        }
        
        return total;
    }
};
