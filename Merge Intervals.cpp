/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    static bool cmp(const Interval& left, const Interval& right)
    {
        return (left.start < right.start);
    }
        
    vector<Interval> merge(vector<Interval> &intervals)
    {   
        vector<Interval> result(intervals);
        if (!result.empty())
        {
            sort(result.begin(), result.end(), cmp);
            auto it1 = result.begin();
            auto it2 = it1 + 1;
            for (; it2 != result.end(); ++it2)
            {
                if (it2->start <= it1->end)
                {
                    it1->end = max(it1->end, it2->end);
                }
                else
                {
                    ++it1;
                    *it1 = *it2;
                }
            }
            ++it1;
            result.erase(it1, result.end());
        }
        return result;
    }
};
