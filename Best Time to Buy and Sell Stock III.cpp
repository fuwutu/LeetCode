class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        
        vector<int> profit_left(prices.size(), 0);
        if (!prices.empty())
        {
            int buy = prices.front();
            for (size_t i = 1; i < prices.size(); ++i)
            {
                int profit = prices[i] - buy;
                profit_left[i] = max(profit_left[i-1], profit);
                buy = min(buy, prices[i]);
            }    
        }
        
        vector<int> profit_right(prices.size(), 0);
        if (!prices.empty())
        {
            int cell = prices.back();
            for (int i = prices.size() - 2; i >= 0; --i)
            {
                int profit = cell - prices[i];
                profit_right[i] = max(profit_right[i+1], profit);
                cell = max(cell, prices[i]);
            }
        }
        
        if (!prices.empty())
        {
            max_profit = profit_left.back();
        }
        
        for (size_t i = 1; i < prices.size(); ++i)
        {
            int sum = profit_left[i-1] + profit_right[i];
            max_profit = max(max_profit, sum);
        }
        
        return max_profit;
    }
};
