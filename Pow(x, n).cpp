class Solution
{
public:
    double pow(double x, int n)
    {
        if (n < 0)
        {
            x = 1.0 / x;
        }
        
        double result = 1.0;
        double power = x;
        
        while (n != 0)
        {
            if (n % 2 != 0)
            {
                result *= power;
            }
            n /= 2;
            power = power * power;
        }
        
        return result;
    }
};

//======================================================================

class Solution2
{
public:
    double pow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        
        int h = n / 2;
        int r = n - h * 2;
        
        double result = pow(x, h);
        result *= result;
        if (r == 1)
        {
            return result * x;
        }
        else if (r == 0)
        {
            return result;
        }
        else
        {
            return result / x;
        }
    }
};
