class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.empty())
        {
            return word2.length();
        }
        else if (word2.empty())
        {
            return word1.length();
        }

        vector<int> dist(word1.length() + 1);
        for (int i1 = 1; i1 <= word1.length(); ++i1)
        {
            dist[i1] = i1;
        }

        for (int i2 = 1; i2 <= word2.length(); ++i2)
        {
            int distLeftUp = dist[0];
            dist[0] = i2;
            for (int i1 = 1; i1 <= word1.length(); ++i1)
            {
                int distLeftUpBack = distLeftUp;
                distLeftUp = dist[i1];
                if (word2[i2-1] == word1[i1-1])
                {
                    dist[i1] = distLeftUpBack;
                }
                else
                {
                    // distLeft -> dist[i1]
                    // distUp -> dist[i1+1]
                    dist[i1] = min(min(dist[i1-1], dist[i1]), distLeftUpBack) + 1;
                }
            }
        }
        return dist.back();
    }
};
