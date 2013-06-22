class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> gray({0});
        int power = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int i = 0; i < power; ++i)
            {
                gray.push_back(gray[i] + power);
            }
            reverse(gray.begin() + power, gray.begin() + power * 2);
            power *= 2;
        }
        return gray;
    }
};
