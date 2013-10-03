class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            answer ^= A[i];
        }
        return answer;
    }
};
