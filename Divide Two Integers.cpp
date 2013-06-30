class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long llDividend = dividend;
        long long llDivisor = divisor;
        int negative = false;
        if (llDividend < 0)
        {
            negative = !negative;
            llDividend = -llDividend;
        }
        if (llDivisor < 0)
        {
            negative = !negative;
            llDivisor = -llDivisor;
        }
        
        long long quotient = 0;
        while (llDividend >= llDivisor)
        {
            int n = 1;
            while ((llDividend >> n) >= llDivisor)
            {
                n += 1;
            }
            quotient += (1 << (n - 1));
            llDividend = llDividend - (llDivisor << (n - 1));
        }
        
        if (negative)
        {
            quotient = -quotient;
        }
        return quotient;
    }
};
