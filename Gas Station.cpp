class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total(gas[0]-cost[0]), mt(total), mi(0);
        for (int i = 1; i < gas.size(); ++i)
        {
            total += (gas[i] - cost[i]);
            if (total < mt)
            {
                mt = total;
                mi = i;
            }
        }

        return total >= 0 ? (mi + 1) % (gas.size()) : -1;
    }
};
