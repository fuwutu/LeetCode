class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string alpha;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (isalnum(*it))
            {
                alpha.push_back(tolower(*it));
            }
        }
        string r(alpha);
        reverse(r.begin(), r.end());
        return alpha == r;
    }
};
