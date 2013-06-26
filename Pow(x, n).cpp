class Solution
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
