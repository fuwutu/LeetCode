class Solution
{
public:
    int maxArea(vector<int> &height)
    {        
        vector<pair<int,int>> height2position(height.size());
        for (int i = 0; i < height.size(); ++i)
        {
            height2position.push_back(make_pair(height[i], i));
        }
        sort(height2position.begin(), height2position.end(), greater<pair<int,int>>());
        int max_area = 0;
        int min_position = height2position[0].second;
        int max_position = height2position[0].second;
        for (int i = 1; i < height2position.size(); ++i)
        {
            min_position = min(min_position, height2position[i].second);
            max_position = max(max_position, height2position[i].second);
            int area = (max_position - min_position) * height2position[i].first;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
