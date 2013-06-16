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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> all_values;
        vector<TreeNode*> level_nodes;
        if (root != NULL)
        {
            level_nodes.push_back(root);
            while (!level_nodes.empty())
            {
                vector<int> level_values;
                for (auto it = level_nodes.begin(); it != level_nodes.end(); ++it)
                {
                    level_values.push_back((*it)->val);
                }
                all_values.push_back(level_values);
                
                vector<TreeNode*> nodes;
                level_nodes.swap(nodes);
                for (auto it = nodes.begin(); it != nodes.end(); ++it)
                {
                    if ((*it)->left != NULL)
                    {
                        level_nodes.push_back((*it)->left);
                    }
                    if ((*it)->right != NULL)
                    {
                        level_nodes.push_back((*it)->right);
                    }
                }
            }
        }
        reverse(all_values.begin(), all_values.end());
        return all_values;
    }
};
