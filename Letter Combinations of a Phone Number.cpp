class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result({""}), temp;
        vector<string> digit2letters({" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        for (auto it = digits.begin(); it != digits.end(); ++it)
        {
            int digit = (*it - '0');
            string letters = digit2letters[digit];

            result.swap(temp);
            result.clear();
            for (size_t i = 0; i < temp.size(); ++i)
            {
                for (size_t j = 0; j < letters.size(); ++j)
                {
                    result.push_back(temp[i]);
                    result.back().push_back(letters[j]);
                }
            }
        }
        return result;
    }
};
