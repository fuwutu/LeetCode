class Solution {
public:
    string multiply(string num1, string num2)
    {
        vector<int> vi1(num1.size());
        for (size_t i = 0; i < num1.size(); ++i)
        {
            vi1[i] = num1[i] - '0';
        }
        reverse(vi1.begin(), vi1.end());
        
        vector<int> vi2(num2.size());
        for (size_t i = 0; i < num2.size(); ++i)
        {
            vi2[i] = num2[i] - '0';
        }
        reverse(vi2.begin(), vi2.end());
        
        vector<int> product(vi1.size() + vi2.size() - 1, 0);
        for (size_t i1 = 0; i1 < vi1.size(); ++i1)
        {
            for (size_t i2 = 0; i2 < vi2.size(); ++i2)
            {
                product[i1+i2] += vi1[i1] * vi2[i2];
            }
        }
        
        for (size_t i = 1; i < product.size(); ++i)
        {
            if (product[i-1] >= 10)
            {
                product[i] += product[i-1] / 10;
                product[i-1] %= 10;
            }
        }
        
        if (product.back() >= 10)
        {
            int carry = product.back() / 10;
            product.back() %= 10;
            product.push_back(carry);
        }
        
        while (product.back() == 0)
        {
            product.pop_back();
        }
        
        if (product.empty())
        {
            product.push_back(0);
        }
        
        reverse(product.begin(), product.end());
        
        string result;
        for (int i : product)
        {
            result.push_back('0' + i);
        }
        return result;
    }
};
