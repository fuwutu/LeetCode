class Solution
{
public:
    vector<int> calc_width_before(const vector<int>& height)
    {
        vector<int> width;
        if (!height.empty())
        {
            width.push_back(1);
            vector<pair<int, int> > height_width({{height[0], 1}});
            for (size_t i = 1; i < height.size(); ++i)
            {
                if (height[i] > height[i - 1])
                {
                    height_width.push_back(make_pair(height[i], 1));
                    width.push_back(1);
                }
                else
                {
                    int w = 1;
                    while (!height_width.empty() && height_width.back().first >= height[i])
                    {
                        w += height_width.back().second;
                        height_width.pop_back();
                    }
                    height_width.push_back(make_pair(height[i], w));
                    width.push_back(w);
                }
            }
        }
        return width;
    }

    int largestRectangleArea(vector<int>& height)
    {
        int largest = 0;
        
        vector<int> left_width = calc_width_before(height);
        
        reverse(height.begin(), height.end());
        vector<int> right_width = calc_width_before(height);
        reverse(right_width.begin(), right_width.end());
        reverse(height.begin(), height.end());
            
        for (int i = 0; i < height.size(); ++i)
        {
            int area = (left_width[i] + right_width[i] - 1) * height[i];
            if (area > largest)
            {
                largest = area;
            }
        }
        
        return largest;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int largest = 0;
        if (!matrix.empty())
        {
            size_t rows = matrix.size();
            size_t columns = matrix[0].size();
            vector<int> height(columns, 0);
            for (size_t r = 0; r < rows; ++r)
            {
                for (size_t c = 0; c < columns; ++c)
                {
                    if (matrix[r][c] == '1')
                    {
                        height[c] += 1;
                    }
                    else
                    {
                        height[c] = 0;
                    }
                }
                int temp_largest = largestRectangleArea(height);
                if (temp_largest > largest)
                {
                    largest = temp_largest;
                }
            }
        }
        
        return largest;
    }
};
