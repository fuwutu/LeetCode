/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        
        vector<pair<TreeNode*,int>> level;
        vector<pair<TreeNode*,int>> next_level;
        
        if (root != nullptr)
        {
            level.push_back(make_pair(root, root->val));
        }
            
        while (!level.empty())
        {
            for (auto p : level)
            {
                if (p.first->left == nullptr && p.first->right == nullptr)
                {
                    sum += p.second;
                }
                if (p.first->left != nullptr)
                {
                    next_level.push_back(make_pair(p.first->left, p.second * 10 + p.first->left->val));
                }
                if (p.first->right != nullptr)
                {
                    next_level.push_back(make_pair(p.first->right, p.second * 10 + p.first->right->val));
                }
            }
            level.swap(next_level);
            next_level.clear();
        }
        
        return sum;
    }
};
