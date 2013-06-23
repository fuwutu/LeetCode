class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        for (char c = '1'; c < '1' + n; ++c)
        {
            s.push_back(c);
        }
        
        int factorial = 1;
        for (int i = 1; i <= n; ++i)
        {
            factorial *= i;
        }
        
        k -= 1;
        
        string result;
        while (n)
        {
            factorial /= n;
            int index = k / factorial;
            k %= factorial;
            n -= 1;
            
            result.push_back(s[index]);
            s.erase(index, 1);
        }
        return result;
    }
};
